// https://leetcode.com/problems/distinct-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1));
        for (int i = 0; i <= s.length(); i++) dp[i][0] = 1;
        for (int i = 1; i <= t.length(); i++) dp[0][i] = 0;
        for (int i = 1; i <= s.length(); i++) {
            for (int k = 1; k <= t.length(); k++) {
                dp[i][k] = dp[i-1][k] % (1 << 30);
                if (s[i-1] == t[k-1]) {
                    dp[i][k] += dp[i-1][k-1] % (1 << 30);
                }
            }
        }
        return dp[s.length()][t.length()];
    }
};
