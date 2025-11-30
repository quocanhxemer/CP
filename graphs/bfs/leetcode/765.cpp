// https://leetcode.com/problems/couples-holding-hands/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            int couple1 = row[2*i] / 2;
            int couple2 = row[2*i+1] / 2;
            adj[couple1].push_back(couple2);
            adj[couple2].push_back(couple1);
        }
        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int count = 1;
            while (!q.empty()) {
                int id = q.front();
                q.pop();
                for (int v : adj[id]) {
                    if (visited[v]) continue;
                    visited[v] = true;
                    count++;
                    q.push(v);
                }
            }
            res += count - 1;
        }

        return res;
    }
};
