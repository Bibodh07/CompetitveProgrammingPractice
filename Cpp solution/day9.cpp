#include <iostream>
#include <vector>
#include <string>


int ways(std::string s) {

    std::vector<int> dp(s.length() + 1, 0);

    dp[0] = 1;
    dp[1] = (s[0] != '0') ? 1 : 0;

    for (size_t i = 2; i <= s.length(); i++) {

        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }

        int twoDigit = std::stoi(s.substr(i - 2, 2));

        if (10 <= twoDigit && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[s.length()];
}