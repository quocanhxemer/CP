// https://leetcode.com/problems/maximize-the-minimum-powered-city/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        auto check = [&](long long max_min) -> bool {
            int kk = k;
            vector<int> installed_station(n, 0);
            long long sum = 0;
            for (int i = 0; i <= r; i++) {
                sum += stations[i];
            }
            for (int i = 0; i < n; i++) {
                long long current_power = sum;
                if (current_power < max_min) {
                    long long needed = max_min - current_power;
                    installed_station[min(n - 1, i + r)] += needed;
                    if (kk < needed) return false;
                    kk -= needed;
                    sum += needed;
                }
                
                if (i >= r) sum -= stations[i-r] + installed_station[i-r];
                if (i + r < n - 1) sum += stations[i+r+1] + installed_station[i+r+1];
            }

            return true;
        };

        long long sum_station = 0;
        for (int i = 0; i < n; i++) {
            sum_station += stations[i];
        }

        long long left = 0, right = sum_station + k;
        long long res = left;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
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

