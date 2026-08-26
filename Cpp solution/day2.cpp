#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>

/*
============================================================
COMPETITIVE PROGRAMMING PRACTICE
Topics:
    1. Two Sum                  -> Hash Map
    2. Valid Anagram             -> Frequency Array
    3. Contains Duplicate II     -> Hash Map + Index Distance
    4. 3Sum                      -> Sorting + Two Pointers
    5. Maximum Sum Subarray K     -> Sliding Window
============================================================
*/


/*
============================================================
1. TWO SUM
============================================================

Problem:
    Given an array and a target k, find two indices whose
    values add up to k.

Example:
    arr = {2, 7, 11, 15}
    k = 9

    2 + 7 = 9

    Answer: {0, 1}

Pattern:
    Hash Map

Key idea:
    For every number:

        needed = target - current

    If 'needed' already exists in the hash map, we found
    the pair.

Why check BEFORE inserting?
    We want to find two DIFFERENT elements.

    Example:
        arr = {3}
        target = 6

    If we inserted 3 first and then checked, we could
    accidentally use the same element twice.

Complexity:
    Time:  O(n) average
    Space: O(n)
============================================================
*/

std::vector<int> sumArray(std::vector<int>& arr, int k)
{
    std::vector<int> result;
    std::unordered_map<int, int> hashMap;

    for (int i = 0; i < arr.size(); ++i)
    {
        int needed = k - arr[i];

        // Check if the number we need was seen before.
        if (hashMap.count(needed))
        {
            result.push_back(i);
            result.push_back(hashMap[needed]);

            return result;
        }

        // Store value -> index.
        hashMap[arr[i]] = i;
    }

    // Empty vector means no pair was found.
    return result;
}


/*
============================================================
2. VALID ANAGRAM
============================================================

Problem:
    Determine whether two strings contain the exact same
    characters with the same frequencies.

Example:
    s = "silent"
    t = "listen"

    Both contain:
        s: 1
        i: 1
        l: 1
        e: 1
        n: 1
        t: 1

    Therefore -> true

Pattern:
    Frequency Array

Key idea:
    Use an array where each index represents a character.

        freq[0] -> 'a'
        freq[1] -> 'b'
        ...
        freq[25] -> 'z'

    For every character in s:
        increment frequency

    For every character in t:
        decrement frequency

    If every value ends at 0, they are anagrams.

Why does this work?

    Example:

        s = "silent"
        t = "listen"

    Every character added by s is eventually cancelled
    by the same character from t.

Important:
    This implementation assumes lowercase English letters.

Complexity:
    Time:  O(n)
    Space: O(1)

    The frequency array always has exactly 26 elements,
    so its space usage is constant.

Edge case:
    If the strings have different lengths, they cannot
    be anagrams.
============================================================
*/

bool anagramCheck(std::string& s, std::string& t)
{
    // Different lengths -> impossible to be anagrams.
    if (s.size() != t.size())
        return false;

    // Index 0 = 'a', index 1 = 'b', ..., index 25 = 'z'.
    int freq[26]{};

    for (int i = 0; i < s.size(); ++i)
    {
        ++freq[s[i] - 'a'];
        --freq[t[i] - 'a'];
    }

    // Every frequency must cancel back to zero.
    for (int count : freq)
    {
        if (count != 0)
            return false;
    }

    return true;
}


/*
============================================================
3. CONTAINS DUPLICATE II / ABSOLUTE INDEX DIFFERENCE
============================================================

Problem:
    Given nums and k, determine whether the same value appears
    twice with an index distance <= k.

Example:
    nums = {1, 2, 3, 1}
    k = 3

    Value 1 appears at:
        index 0
        index 3

    |3 - 0| = 3

    Therefore -> true

Pattern:
    Hash Map + Index Tracking

Key idea:
    Store:

        value -> most recent index

    When we see a value again:

        current index - previous index <= k

    If yes, return true.

Important insight:
    We only need the MOST RECENT index.

    Why?

    Suppose we have:

        value at index 1
        value again at index 10
        value again at index 12

    When checking index 12:

        12 - 10 = 2  <- useful

    while:

        12 - 1 = 11   <- farther away

    Therefore, keeping the latest index gives us the
    smallest possible distance.

Complexity:
    Time:  O(n) average
    Space: O(n)
============================================================
*/

bool absdiffcheck(std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); ++i)
    {
        // Have we seen this value before?
        if (map.count(nums[i]))
        {
            // Check distance between current and previous index.
            if (i - map[nums[i]] <= k)
                return true;
        }

        // Store/update the most recent index.
        map[nums[i]] = i;
    }

    return false;
}


/*
============================================================
4. 3SUM
============================================================

Problem:
    Find all unique triplets whose values add up to 0.

Example:
    nums = {-1, 0, 1, 2, -1, -4}

    Valid triplets:

        {-1, -1, 2}
        {-1, 0, 1}

Pattern:
    Sorting + Two Pointers

Why sort?

    Sorting gives us a predictable relationship between
    left and right values.

    If:

        sum < 0

    we need a larger value -> move LEFT forward.

    If:

        sum > 0

    we need a smaller value -> move RIGHT backward.

Algorithm:

    1. Sort the array.

    2. Pick nums[i] as the first element.

    3. Set:
           left = i + 1
           right = end

    4. While left < right:

           sum < 0 -> left++
           sum > 0 -> right--
           sum == 0 -> save triplet and move both

Complexity:
    Sorting: O(n log n)
    Two-pointer search for each i: O(n)

    Total: O(n²)

Space:
    O(1) auxiliary space
    (not counting the output vector)

IMPORTANT:
    This is currently the BASIC 3Sum implementation.

    A complete 3Sum solution should also skip duplicates:

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

    and skip duplicate left/right values after finding
    a valid triplet.

============================================================
*/

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    std::vector<std::vector<int>> result;

    // Sorting enables the two-pointer technique.
    std::sort(nums.begin(), nums.end());

    // i represents the first number of the triplet.
    for (int i = 0; i < nums.size() - 2; ++i)
    {
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0)
            {
                // Need a larger number.
                ++left;
            }
            else if (sum > 0)
            {
                // Need a smaller number.
                --right;
            }
            else
            {
                // Found a valid triplet.
                result.push_back(
                    { nums[i], nums[left], nums[right] }
                );

                ++left;
                --right;
            }
        }
    }

    return result;
}


/*
============================================================
5. MAXIMUM SUM SUBARRAY OF SIZE K
============================================================

Problem:
    Find the maximum sum of any contiguous subarray containing
    exactly k elements.

Example:

    nums = {2, 1, 5, 1, 3, 2}
    k = 3

    Windows:

        {2, 1, 5} -> 8
        {1, 5, 1} -> 7
        {5, 1, 3} -> 9
        {1, 3, 2} -> 6

    Answer: 9

Pattern:
    Fixed-Size Sliding Window

Naive approach:
    Calculate every window from scratch.

    Time: O(n * k)

Better approach:
    Reuse the previous window's sum.

When the window moves:

        OLD WINDOW:
        [2, 1, 5]

        NEW WINDOW:
           [1, 5, 1]

    We:

        subtract the element leaving
        add the element entering

        newSum = oldSum - outgoing + incoming

Key line:

        windowSum += nums[right];
        windowSum -= nums[right - k];

Complexity:
    Time:  O(n)
    Space: O(1)

Why O(n)?

    Every element is processed only a constant number
    of times instead of recalculating every window.
============================================================
*/

int maxSumSubarray(const std::vector<int>& nums, int k)
{
    int windowSum{ 0 };

    // Build the first window.
    for (int i{ 0 }; i < k; ++i)
        windowSum += nums[i];

    int maxSum{ windowSum };

    // Slide the window across the array.
    for (int right{ k }; right < nums.size(); ++right)
    {
        // Add the new element entering the window.
        windowSum += nums[right];

        // Remove the old element leaving the window.
        windowSum -= nums[right - k];

        // Update the maximum.
        maxSum = std::max(maxSum, windowSum);
    }

    return maxSum;
}


/*
============================================================
MAIN
============================================================
*/

int main()
{
    return 0;
}