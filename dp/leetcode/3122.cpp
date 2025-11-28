// https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        vector<vector<int>> cost(grid[0].size(), vector<int>(10));
        for (int k = 0; k < grid[0].size(); k++) {
            int count[10] = {0};
            for (int i = 0; i < grid.size(); i++) {
                count[grid[i][k]]++;
            }
            for (int i = 0; i <= 9; i++) {
                cost[k][i] = grid.size() - count[i];
            }
        }

        vector<vector<int>> dp(grid[0].size(), vector<int>(10));
        for (int i = 0; i <= 9; i++) {
            dp[0][i] = cost[0][i];
        }
        for (int i = 1; i < grid[0].size(); i++) {
            for (int num = 0; num <= 9; num++) {
                dp[i][num] = cost[i][num];
                int mn = INT_MAX;
                // smallest cost of previous column with num != k
                for (int k = 0; k <= 9; k++) {
                    if (num == k) continue;
                    mn = min(mn, dp[i-1][k]);
                }
                dp[i][num] += mn;
            }
        }

        int res = INT_MAX;
        for (int i = 0; i <= 9; i++) {
            res = min(res, dp[grid[0].size() - 1][i]);
        }
        return res;
    }
};
