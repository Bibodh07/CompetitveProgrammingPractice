#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>



int buySellStockWithCoolDown(std::vector<int> nums)
{
    std::vector<int> hold(nums.size(), 0);
    std::vector<int> cash(nums.size(), 0);
    std::vector<int> coolDown(nums.size(), 0);


    hold[0] = -nums[0];
    coolDown[0] = -100000000000000000; //non existent

    for(size_t i =1; i < nums.size(); i++)
    {

        hold[i] = std::max(hold[i-1], cash[i-1] - nums[i]);
        cash[i] = std::max(cash[i-1], coolDown[i-1]);
        coolDown[i] = hold[i-1] + nums[i];

    }

    return *(std::max_element(cash.begin(), cash.end()));
}


class Solution {
public:
    bool canPartition(std::vector<int>& nums) {

        int total = 0;

        for (int x : nums)
            total += x;

        if (total % 2)
            return false;

        int target = total / 2;

        std::vector<std::vector<bool>> dp(
            nums.size() + 1,
            std::vector<bool>(target + 1, false)
        );

        dp[0][0] = true;

        for (int i = 1; i <= nums.size(); i++) {

            for (int s = 0; s <= target; s++) {

                bool skip = dp[i - 1][s];

                bool take = false;

                if (s >= nums[i - 1])
                    take = dp[i - 1][s - nums[i - 1]];

                dp[i][s] = skip || take;
            }
        }

        return dp[nums.size()][target];
    }
};