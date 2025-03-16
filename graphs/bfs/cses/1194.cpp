// https://cses.fi/problemset/task/1194/
// MONSTERS

#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1000][1000];
char path[1000][1000];
pair<int, int> p[1000][1000];

int dplayer[1000][1000];
int dmonsters[1000][1000];

vector<pair<int, int>> monsters;
pair<int, int> player;

// directions: U D L R
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
char directions[] = {'U', 'D', 'L', 'R'};

int validPosition(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int isExit(int i, int j) {
    return i == 0 || i == n - 1 || j == 0 || j == m - 1;
}

void printPath(int x, int y) {
    cout << "YES" << endl;
    cout << dplayer[x][y] << endl;

    string res = "";
    pair<int, int> current = {x, y};
    while (current != player) {
        res = path[current.first][current.second] + res;
        current = p[current.first][current.second];
    }

    cout << res << endl;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 'M')
                monsters.push_back({i, j});

            if (grid[i][j] == 'A') {
                if (isExit(i, j)) {
                    cout << "YES" << endl;
                    cout << 0 << endl;
                    return 0;
                }
                player = {i, j};
            }
        }
    }

    vector<pair<int, int>> exits;

    memset(dplayer, -1, sizeof(dplayer));
    memset(path, 0, sizeof(path));
    queue<pair<int, int>> q;
    q.push(player);
    dplayer[player.first][player.second] = 0;

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int x = i + di[k];
            int y = j + dj[k];

            if (!validPosition(x, y) || dplayer[x][y] != -1)
                continue;

            if (grid[x][y] != '#') {
                dplayer[x][y] = dplayer[i][j] + 1;
                p[x][y] = {i, j};
                path[x][y] = directions[k];
                q.push({x, y});

                if (isExit(x, y)) {
                    exits.push_back({x, y});
                }
            }
        }
    }

    memset(dmonsters, -1, sizeof(dmonsters));
    for (pair<int, int> m : monsters) {
        q.push(m);
        dmonsters[m.first][m.second] = 0;
    }

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int x = i + di[k];
            int y = j + dj[k];

            if (!validPosition(x, y) || dmonsters[x][y] != -1)
                continue;

            if (grid[x][y] != '#') {
                dmonsters[x][y] = dmonsters[i][j] + 1;
                q.push({x, y});
            }
        }
    }

    for (auto [i, j] : exits) {
        if (dmonsters[i][j] == -1 || dmonsters[i][j] > dplayer[i][j]) {
            printPath(i, j);
            return 0;
        }
    }

    cout << "NO" << endl;
}
