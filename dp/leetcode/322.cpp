// https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n + 1][amount + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = amount + 1;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                }
            }
        }

        if (dp[n][amount] > amount) {
            return -1;
        }

        return dp[n][amount];
    }
};
