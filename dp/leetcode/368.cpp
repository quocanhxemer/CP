// https://leetcode.com/problems/largest-divisible-subset/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int dp[1000];
        int backtrack[1000];
        dp[0] = 1;
        memset(backtrack, -1, sizeof(backtrack));

        for (int i = 1; i < nums.size(); i++) {
            int max_size = 0;
            int max_index = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && max_size < dp[j]) {
                    max_size = dp[j];
                    max_index = j;
                }
            }

            backtrack[i] = max_index;
            dp[i] = max_size + 1;
        }

        int max_size = 0;
        int max_index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (max_size < dp[i]) {
                max_size = dp[i];
                max_index = i;
            }
        }

        vector<int> res;
        while (max_index != -1) {
            res.push_back(nums[max_index]);
            max_index = backtrack[max_index];
        }

        return res;
    }
};
