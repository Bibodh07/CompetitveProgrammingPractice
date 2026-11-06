#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>


std::vector<int> nextGreater(const std::vector<int>& nums1, const std::vector<int>& nums2)
{
    std::unordered_map<int, int> tracker;
    std::stack<int> st;                      // holds values, decreasing from bottom to top

    for (int i = (int)nums2.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() < nums2[i])
            st.pop();                        // smaller ones can never be an answer for anyone to the left

        tracker[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);                   // always push
    }

    std::vector<int> result;
    for (int x : nums1)
        result.push_back(tracker[x]);
    return result;
}


int lengthOfLongestSubstring(const std::string& s)
{
    std::unordered_set<char> st;
    int bestLength = 0;
    int l = 0;

    for (int r = 0; r < (int)s.size(); r++)
    {
        while (st.find(s[r]) != st.end())
        {
            st.erase(s[l]);
            l++;
        }
        st.insert(s[r]);                          // the missing line
        bestLength = std::max(bestLength, r - l + 1);
    }
    return bestLength;
}

int longestContinuousAscending(const std::vector<int>& nums)
{
    int best_length = 0;
    int l = 0;
    for (int r = 0; r < (int)nums.size(); r++)
    {
        if (r > 0 && nums[r] <= nums[r-1])   // streak broken
            l = r;
        best_length = std::max(best_length, r - l + 1);
    }
    return best_length;
}