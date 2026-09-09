#include <iostream>
#include <vector> 


int ClimbingStairs(int n, std::vector<int> &dp)
{
    //baseCases
    if(n<=1)
    {
        return n;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = ClimbingStairs(n-1, dp) + ClimbingStairs(n-2, dp);

    return dp[n];

}

int HouseRobbery(std::vector<int> nums)
{
    int length = nums.size();
    std::vector<int> dp(length, -1);

    if (nums.size() == 0){
        return 0;
    }

    if (nums.size() == 1)
    {
        return nums[0];
    }


    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for (size_t i = 2; i< nums.size(); i++)
    {
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
    }

    return dp[length -1];

}



int main()
{
    return 0;
}