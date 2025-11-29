// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> balance(n, 0);

        // optimize O(n)
        if (k >= n) {
            int sum = 0;
            for (int i = 1; i < n; i++) {
                sum += max(0, prices[i] - prices[i-1]);
            }
            return sum;
        }
        
        for (int i = 0; i < k; i++) {
            int sell_balance = -prices[0];
            for (int j = 1; j < n; j++) {
                sell_balance = max(sell_balance, balance[j] - prices[j]); 
                balance[j] = max(balance[j-1], prices[j] + sell_balance);
            }
        }

        return balance[n-1];
    }
};
