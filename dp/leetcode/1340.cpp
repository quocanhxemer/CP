// https://leetcode.com/problems/jump-game-v/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            left[i] = st.empty() ? 0 : st.top()+1;
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            right[i] = st.empty() ? n-1 : st.top()-1;
            st.push(i);
        }

        map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }

        vector<int> res(n, 1);
        while (!m.empty()) {
            auto it = m.begin();
            int val = it->first;
            for (int i : m[val]) {
                int l = max(left[i], i - d);
                int r = min(right[i], i + d);
                for (int j = l; j <= r; j++) { // i can jump to j
                    if (i == j) continue;
                    res[i] = max(res[i], res[j]+1);
                }
            }
            m.erase(it);
        }

        int mx = 1;
        for (int i : res) {
            mx = max(mx, i);
        }
        return mx;
    }
};
