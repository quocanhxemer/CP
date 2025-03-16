// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1000][1000];
int visited[1000][1000];

int di[] = {0, 0, 1, -1};
int dj[] = {-1, 1, 0, 0};

void dfs(int i, int j) {
    if (visited[i][j]) {
        return;
    }
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int u = i + di[k];
        int v = j + dj[k];

        if (u < 0 || u >= n || v < 0 || v >= m) {
            continue;
        }

        if (grid[u][v] == '.') {
            dfs(u, v);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '.') {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count << endl;
}
