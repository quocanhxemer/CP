// https://leetcode.com/problems/minimum-height-trees/description/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }

        vector<int> adj[n];

        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        int d[20000];

        memset(d, -1, sizeof(d));
        q.push(0);
        d[0] = 0;
        int last;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (d[v] != -1)
                    continue;

                d[v] = d[u] + 1;
                last = v;
                q.push(v);
            }
        }

        int first = last;
        memset(d, -1, sizeof(d));
        q.push(first);
        d[first] = 0;
        int p[20000];
        p[first] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (d[v] != -1)
                    continue;

                d[v] = d[u] + 1;
                p[v] = u;
                last = v;
                q.push(v);
            }
        }

        int c = last;
        for (int i = 0; i < d[last] / 2; i++) {
            c = p[c];
        }

        if (d[last] % 2) {
            return vector<int>{c, p[c]};
        }

        return vector<int>{c};
    }
};
