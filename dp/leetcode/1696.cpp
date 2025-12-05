// https://leetcode.com/problems/jump-game-vi/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        k = min(k, n);

        vector<int> dp(n);
        dp[0] = nums[0];
        deque<int> q;
        q.push_back(0);

        for (int i = 1; i < k; i++) {
            dp[i] = dp[q.front()] + nums[i];
            while (!q.empty() && dp[q.back()] < dp[i]) q.pop_back();
            q.push_back(i);
        }

        for (int i = k; i < n; i++) {
            dp[i] = dp[q.front()] + nums[i];
            if (i - k >= q.front()) q.pop_front();
            while (!q.empty() && dp[q.back()] < dp[i]) q.pop_back();
            q.push_back(i);
        }

        return dp[n-1];
    }
};
