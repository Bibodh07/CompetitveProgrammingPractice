#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int maxProfit(std::vector<int> costs, std::vector<int> profits, int B)
{

    std::vector<std::vector<int>> dp(
    costs.size() + 1,
    std::vector<int>(B + 1, 0)
    );  

    int earned = 0;

    for(int i=0; i < costs.size(); i++)
    {
        if(B - costs[i] > 0){
             
            int profit = dp[i][B-costs[i]] + profits[i];
            int take = profit;
            int skip = earned;
        }
    }

    return 0;
}