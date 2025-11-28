// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = 0;
        int mn = prices[0];
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i-1], prices[i] - mn);
            mn = min(mn, prices[i]);
        }

        suff[n-1] = 0;
        int mx = prices[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i+1], mx - prices[i]);
            mx = max(mx, prices[i]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, pref[i] + suff[i]);
        }
        return res;
    }
};
