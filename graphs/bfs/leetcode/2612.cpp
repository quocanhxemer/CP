// https://leetcode.com/problems/minimum-reverse-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        set<int> s;
        for (int i : banned) s.insert(i);

        vector<int> res(n, -1);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < k / 2; j++) {
                int l = i + j;
                int r = i + k - j - 1;
                if (s.count(l) || s.count(r)) continue;
                adj[l].push_back(r);
                adj[r].push_back(l);
            }
        }

        queue<int> q;
        q.push(p);
        res[p] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (res[v] != -1) continue;
                res[v] = res[u] + 1;
                q.push(v);
            }
        }
        return res;
    }
};
