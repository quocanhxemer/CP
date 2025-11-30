// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(vector<int>& candies, long long k, int num) {
        if (num == 0) return true;
        for (int i = 0; i < candies.size(); i++) {
            int kids = candies[i] / num;
            k -= kids;
            if (k <= 0) return true;
        }
        return k <= 0;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 0;
        int right = 1e7;
        int res = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(candies, k, mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
