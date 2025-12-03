// https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int> start(n);
        vector<int> end(n);
        for (int i = 0; i < n; i++) {
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        auto find = [&](vector<int>& a, int v) -> int {
            int l = 0, r = n - 1;
            int f = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (a[mid] <= v) {
                    l = mid + 1;
                    f = mid;
                } else {
                    r = mid - 1;
                }
            }
            return f;
        };

        vector<int> res;
        for (int i : people) {
            int s = find(start, i);
            int e = find(end, i-1);
            res.push_back(s - e);
        }

        return res;
    }
};

