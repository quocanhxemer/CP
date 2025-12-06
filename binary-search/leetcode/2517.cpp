// https://leetcode.com/problems/maximum-tastiness-of-candy-basket/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();

        sort(price.begin(), price.end());

        auto check = [&](int n) -> bool {
            int count = 0; 
            int target = price[0];
            for (int i : price) {
                if (i >= target) {
                    count++;
                    target = i + n;
                }
            }
            return count >= k;
        };

        int left = 0, right = 1e9;
        int res = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};
