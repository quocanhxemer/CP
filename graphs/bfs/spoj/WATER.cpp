#include <bits/stdc++.h>

using namespace std;

int ptoi(int i, int j) {
    return i * 100 + j;
}

int run() {
    int n, m;
    cin >> n >> m;

    int low_points = n * m;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    int matrix[n][m];
    int border[n][m] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                pq.push({matrix[i][j], ptoi(i, j)});
                border[i][j] = 1;
                low_points--;
            }
        }
    }

    int sum = 0;

    while (low_points) {
        int i = pq.top().second / 100;
        int j = pq.top().second % 100;
        pq.pop();

        int moveX[] = {0, 0, 1, -1};
        int moveY[] = {1, -1, 0, 0};
        for (int k = 0; k < 4; k++) {
            int u = i + moveX[k];
            int v = j + moveY[k];

            if (u < 0 || u >= n || v < 0 || v >= m) {
                continue;
            }

            if (!border[u][v]) {
                border[u][v] = 1;
                pq.push({matrix[u][v], ptoi(u, v)});
                int diff = matrix[i][j] - matrix[u][v];
                if (diff > 0) {
                    sum += diff;
                    matrix[u][v] += diff;
                    pq.push({matrix[u][v], ptoi(u, v)});
                }
                low_points--;
            }
        }
    }

    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cout << run() << endl;
        string s;
        getline(cin, s);
    }
}
