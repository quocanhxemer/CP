// https://leetcode.com/problems/shortest-bridge/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int shortestBridge(vector<vector<int>>& grid) {
        int di[] = {0, 0, -1, 1};
        int dj[] = {1, -1, 0, 0};

        int n = grid.size();

        int island[100][100];
        memset(island, 0, sizeof(island));

        pair<int, int> first_one;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    first_one = {i, j};
                    island[i][j] = 1;
                    goto here;
                }
            }
        }
        here:

        queue<pair<int, int>> q;
        int d[100][100];
        memset(d, -1, sizeof(d));
        q.push(first_one);
        d[first_one.first][first_one.second] = 0;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int u = i + di[k];
                int v = j + dj[k];

                if (isvalid(u, v, n) && d[u][v] == -1 && grid[u][v]) {
                    d[u][v] = d[i][j] + 1;
                    island[u][v] = 1;
                    q.push({u, v});
                }
            }
        }

        pair<int, int> second_one;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && island[i][j] != 1) {
                    second_one = {i, j};
                    island[i][j] = 2;
                    goto here2;
                }
            }
        }
        here2:

        memset(d, -1, sizeof(d));
        q.push(second_one);
        d[second_one.first][second_one.second] = 0;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int u = i + di[k];
                int v = j + dj[k];

                if (isvalid(u, v, n) && d[u][v] == -1 && grid[u][v]) {
                    d[u][v] = d[i][j] + 1;
                    island[u][v] = 2;
                    q.push({u, v});
                }
            }
        }

        memset(d, -1, sizeof(d));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (island[i][j] == 1) {
                    q.push({i, j});
                    d[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int u = i + di[k];
                int v = j + dj[k];

                if (isvalid(u, v, n) && d[u][v] == -1) {
                    d[u][v] = d[i][j] + 1;
                    q.push({u, v});

                    if (island[u][v] == 2) {
                        return d[u][v] - 1;
                    }
                }
            }
        }

        return -1;
    }

   private:
    int isvalid(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
};
