// https://cses.fi/problemset/task/1194/
// MONSTERS

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> exits;

    string matrix[n];
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];

        if (i == 0 || i == n - 1) {
            for (int j = 1; j < m - 1; j++) {
                if (matrix[i][j] == 'A') {
                    cout << "YES" << endl << 0 << endl;
                    return 0;
                }
                if (matrix[i][j] == '.') {
                    exits.push_back({i, j});
                }
            }
        }

        if (matrix[i][0] == '.') {
            exits.push_back({i, 0});
        }

        if (matrix[i][m - 1] == '.') {
            exits.push_back({i, m - 1});
        }

        if (matrix[i][0] == 'A' || matrix[i][m - 1] == 'A') {
            cout << "YES" << endl << 0 << endl;
            return 0;
        }
    }

    int moveX[] = {0, 0, -1, 1};
    int moveY[] = {-1, 1, 0, 0};
    char directions[] = {'R', 'L', 'D', 'U'};
    char path[n][m];

    int d[n][m];
    for (auto [x, y] : exits) {
        int monsters_distance = INT_MAX;
        int player_distance = -1;

        queue<pair<int, int>> q;
        int visited[n][m];
        memset(visited, 0, sizeof(visited));
        pair<int, int> p[n][m];
        q.push({x, y});
        visited[x][y] = 1;
        d[x][y] = 0;
        p[x][y] = {-1, -1};
        path[x][y] = 's';

        pair<int, int> player_coor;

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int u = i + moveX[k];
                int v = j + moveY[k];

                if (u < 0 || u >= n || v < 0 || v >= m) {
                    continue;
                }

                if (visited[u][v]) {
                    continue;
                }

                if (matrix[u][v] == '#') {
                    continue;
                }

                d[u][v] = d[i][j] + 1;
                p[u][v] = {i, j};
                path[u][v] = directions[k];
                visited[u][v] = 1;
                q.push({u, v});

                if (matrix[u][v] == 'A') {
                    player_distance = d[u][v];
                    player_coor = {u, v};
                }

                if (matrix[u][v] == 'M' && d[u][v] < monsters_distance) {
                    monsters_distance = d[u][v];
                }
            }
        }

        if (player_distance != -1 && player_distance < monsters_distance) {
            cout << "YES" << endl;
            cout << d[player_coor.first][player_coor.second] << endl;
            pair<int, int> c = player_coor;
            while (true) {
                if (path[c.first][c.second] == 's') {
                    break;
                }
                cout << path[c.first][c.second];
                c = p[c.first][c.second];
            }
            cout << endl;

            return 0;
        }
    }

    cout << "NO" << endl;
}
