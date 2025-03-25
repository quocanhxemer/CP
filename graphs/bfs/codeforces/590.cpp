// https://codeforces.com/problemset/problem/590/C
// Three States

#include <bits/stdc++.h>

using namespace std;

int n, m;
char grid[1000][1000];
int d[1000][1000];
int cost[1000][1000];

deque<pair<int, int>> q;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

vector<pair<int, int>> roads;

int valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int is_land(int i, int j) {
    return valid(i, j) &&
           (grid[i][j] == '1' || grid[i][j] == '2' || grid[i][j] == '3');
}

int bfs(int land) {
    int found_land = 0;
    memset(d, -1, sizeof(d));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == land) {
                q.push_back({i, j});
                d[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop_front();

        for (int k = 0; k < 4; k++) {
            int u = i + di[k];
            int v = j + dj[k];

            if (!valid(u, v) || grid[u][v] == '#')
                continue;

            if (d[u][v] != -1)
                continue;

            if (is_land(u, v)) {
                d[u][v] = d[i][j];
                q.push_front({u, v});
                found_land = 1;
            } else {
                d[u][v] = d[i][j] + 1;
                q.push_back({u, v});
            }

            cost[u][v] += d[u][v];
        }
    }

    return found_land;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int i = '1'; i <= '3'; i++) {
        if (!bfs(i)) {
            cout << -1 << '\n';
            return 0;
        }
    }

    int min_cost = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#')
                continue;

            if (grid[i][j] == '.') {
                if (!cost[i][j])
                    continue;
                cost[i][j] -= 2;
            }

            if (min_cost > cost[i][j])
                min_cost = cost[i][j];
        }
    }

    cout << min_cost << '\n';
}
