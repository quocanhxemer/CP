// https://leetcode.com/problems/unique-paths-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));

        m = grid.size();
        n = grid[0].size();
        int total = n * m - 1;
        int count = 0;

        // starting point
        int x, y;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
                if (grid[i][j] == -1) {
                    total--;
                }
            }
        }

        auto dfs = [&](auto&& self, int x, int y) -> void {
            auto valid = [&](int i, int j) -> bool {
                if (i < 0 || j < 0 || i >= m || j >= n) {
                    return false;
                }
                if (grid[i][j] == -1)
                    return false;
                return true;
            };

            if (grid[x][y] == 2) {
                if (dist[x][y] == total) {
                    count++;
                }
                return;
            }

            for (int i = 0; i < 4; i++) {
                int vx = x + dx[i];
                int vy = y + dy[i];
                if (!valid(vx, vy))
                    continue;
                if (dist[vx][vy] != -1)
                    continue;
                dist[vx][vy] = dist[x][y] + 1;
                self(self, vx, vy);
                dist[vx][vy] = -1;
            }
        };

        dist[x][y] = 0;
        dfs(dfs, x, y);
        return count;
    }
};
