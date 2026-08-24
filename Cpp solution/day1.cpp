#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

/*
============================================================
Problem 1: Contains Duplicate
============================================================

Given an integer array nums, return true if any value appears
at least twice in the array. Otherwise, return false.

Example:
Input:  [1, 2, 3, 1]
Output: true

Input:  [1, 2, 3, 4]
Output: false

Approach:
Use an unordered_set to keep track of numbers we have already
seen. If the current number is already in the set, a duplicate
exists.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

bool containsDuplicate(const std::vector<int>& nums)
{
    std::unordered_set<int> seen;

    for (int num : nums)
    {
        if (seen.count(num))
        {
            return true;
        }

        seen.insert(num);
    }

    return false;
}


/*
============================================================
Problem 2: Subarray Sum Equals K
============================================================

Given an integer array nums and an integer k, return the total
number of continuous subarrays whose sum equals k.

A subarray must contain consecutive elements.

Example:
Input:  nums = [1, 1, 1], k = 2
Output: 2

The valid subarrays are:
[1, 1] at indices 0-1
[1, 1] at indices 1-2

Approach:
Use a running prefix sum and an unordered_map to store the
frequency of previously seen prefix sums.

If:

    prefixSum[B] - prefixSum[A] = k

then:

    prefixSum[A] = prefixSum[B] - k

Therefore, for each current prefix sum, we check whether
prefixSum - k has appeared before.

prefixSum[0] = 1 represents an empty prefix before the array,
allowing us to correctly count subarrays beginning at index 0.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

int subArraySum(const std::vector<int>& nums, int k)
{
    int sumArray = 0;
    int count = 0;

    // prefix sum -> frequency
    std::unordered_map<int, int> prefixSum;

    // Empty prefix before the array
    prefixSum[0] = 1;

    for (int num : nums)
    {
        // Update current prefix sum
        sumArray += num;

        // Look for an earlier prefix sum such that:
        // sumArray - previousSum = k
        if (prefixSum.count(sumArray - k))
        {
            count += prefixSum[sumArray - k];
        }

        // Record the current prefix sum
        prefixSum[sumArray]++;
    }

    return count;
}


/*
============================================================
Problem 3: Longest Substring Without Repeating Characters
============================================================

Given a string s, find the length of the longest substring
that contains no repeating characters.

A substring must contain consecutive characters.

Example:
Input:  s = "abcabcbb"
Output: 3

The longest substring without repeating characters is "abc".

Example:
Input:  s = "bbbbb"
Output: 1

Example:
Input:  s = "pwwkew"
Output: 3

Approach:
Use a sliding window with two pointers, left and right.

The unordered_set stores the characters currently inside
the window.

The right pointer expands the window.

If a duplicate character is found, move the left pointer
forward and remove characters from the set until the window
contains only unique characters again.

For every valid window, calculate its length and update
the maximum.

Time Complexity: O(n)
Space Complexity: O(n)
*/

int longestRepeatingCharacter(const std::string& s)
{
    int l = 0;
    int result = 0;

    std::unordered_set<char> characterSet;

    for (int r = 0; r < s.length(); r++)
    {
        // Shrink the window until s[r] is no longer a duplicate
        while (characterSet.count(s[r]))
        {
            characterSet.erase(s[l]);
            l++;
        }

        // Add the new character to the window
        characterSet.insert(s[r]);

        // Update the maximum window length
        result = std::max(result, r - l + 1);
    }

    return result;
}


int main()
{
    std::vector<int> nums = {1, 2, 3, 4};

    std::cout << std::boolalpha
              << containsDuplicate(nums);

    return 0;
}