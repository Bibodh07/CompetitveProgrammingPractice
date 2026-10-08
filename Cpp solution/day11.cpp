#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>




int deleteAndEarn(std::vector<int> nums)
{

    int max_val = *std::max_element(nums.begin(), nums.end());
    std::vector<int> points(max_val+1, 0);
    std::vector<int> dp(points.size(), 0);

    for (int num : nums){
        points[num] += num;
    }

    dp[0] = 0;
    if (max_val >= 1)
        {
            dp[1] = points[1];
        }

    for (size_t i =2; i<=max_val; i++)
    {
        dp[i] = std::max(dp[i-1], dp[i-2] + points[i]);
    }

    return *(std::max_element(dp.begin(), dp.end()));
    
}


int stockBuyandSell(std::vector<int> nums)
{
    std::vector<int> hold(nums.size(), 0);
    std::vector<int> cash(nums.size(), 0);


    cash[0] = 0;
    hold[0] = -nums[0];

    for(size_t i = 1; i < nums.size(); i++)
    {
        hold[i] = std::max(hold[i-1], cash[i-1] - nums[i]);
        cash[i] = std::max(cash[i-1], hold[i-1] + nums[i]);
    }

    return cash.back();
}

int stockBuyandSellwTransition(std::vector<int> nums)
{

    std::vector<int> hold(nums.size(), 0);
    std::vector<int> cash(nums.size(), 0);
    std::vector<int> transition(nums.size(), 0);


    cash[0] = 0;
    hold[0] = -nums[0];
    transition[0] = INT_MIN;

    for(size_t i = 1; i < nums.size(); i++)
    {
        hold[i] = std::max(hold[i-1], cash[i-1] - nums[i]);
        cash[i] = std::max(cash[i-1], transition[i-1]);
        transition[i] = hold[i-1] + nums[i];

    }



}