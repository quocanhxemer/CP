// https://leetcode.com/problems/count-special-triplets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mk; // seen k + freq
        unordered_map<int, int> mj; // seen j + freq

        int mod = 1e9 + 7;

        int res = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                res = (res + mj[num / 2]) % mod;
            }
            mj[num] = (mj[num] + mk[num * 2]) % mod;
            mk[num]++;
        }

        return res;
    }
};

