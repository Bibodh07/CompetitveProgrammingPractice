#Practice for OA's and competitve programming. 
#Starting from the Basics

'''
Problem: Contains Duplicate

Given an integer array nums, return true if any value appears at least
twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
- 1 <= nums.length <= 100000
- -10^9 <= nums[i] <= 10^9

Approach:
Use an unordered_set to keep track of numbers that have already been seen.
While iterating through the array:
    - If the current number is already in the set, return true.
    - Otherwise, insert it into the set.
If the loop finishes, no duplicates exist, so return false.

Time Complexity: O(n)
Space Complexity: O(n)
*/

'''

def containsDuplicate(nums):

    hashSet = set()
    result = False
    for i in nums:
        if hashSet and i in hashSet:
            return True
        hashSet.add(i)
    return result


nums = [1,2,3,4]

print(containsDuplicate(nums))