#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


int longestPairChain(std::vector<std::vector<int>> nums)
{
    std::sort(nums.begin(), nums.end());

    std::vector<int> dp(nums.size(), 1);

    for (size_t i = 1; i < nums.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (nums[j][1] < nums[i][0])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *(std::max_element(dp.begin(), dp.end()));
}




int findNumberOfLIS(std::vector<int>& nums)
{
    int n = nums.size();

    std::vector<int> dp(n, 1);
    std::vector<int> count(n, 1);

    int maxLen = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                // Found a longer LIS ending at i
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                // Found another way to get the same best length
                else if (dp[j] + 1 == dp[i])
                {
                    count[i] += count[j];
                }
            }
        }

        maxLen = std::max(maxLen, dp[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxLen)
        {
            ans += count[i];
        }
    }

  

    return ans;
}





static bool cmp(std::vector<int>& a, std::vector<int>& b) {

        if (a[0] == b[0])
            return a[1] < b[1];

        return a[0] < b[0];
    }

    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), cmp);

        int n = envelopes.size();

        std::vector<int> dp(n, 1);

        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (envelopes[j][0] < envelopes[i][0] &&
                    envelopes[j][1] < envelopes[i][1]) {

                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }

            ans = std::max(ans, dp[i]);
        }

        return ans;
    }


    int findLongestChain(std::vector<std::vector<int>>& pairs)
{
    sort(pairs.begin(), pairs.end());

    int n = pairs.size();

    std::vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (pairs[j][1] < pairs[i][0])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        ans = std::max(ans, dp[i]);
    }

    return ans;
}