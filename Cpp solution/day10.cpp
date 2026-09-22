#include <iostream>
#include <vector>
#include <utility>


int stateMachine_dp(std::vector<int> nums)
{


    std::vector<int> hold;
    std::vector<int> cash;

    cash[0] = 0;
    hold[0] = -(nums[0]);

    for (size_t i = 1; i < nums.size(); i++){

        cash[i] = std::max(cash[i-1], hold[i-1] + nums[i]);
        hold[i] = std::max(hold[i-1], cash[i-1] - nums[i]);

    }



    return cash[nums.size() - 1];
}



int LIS(std::vector<int> nums)
{
    int n = nums.size();

    std::vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}