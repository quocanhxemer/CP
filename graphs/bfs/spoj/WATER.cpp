#include <bits/stdc++.h>

using namespace std;

int input[100][100];
int source[100][100];
bool filled[100][100];
int height[100][100];

bool isFilled(int start, int n, int m) {
    int sourceStart = source[start / 100][start % 100];
    if (sourceStart != -1) {
        if (filled[sourceStart / 100][sourceStart % 100]) {
            return true;
        }
    }

    queue<int> q;
    q.push(start);
    bool visited[100][100] = {false};

    while (!q.empty()) {
        int i = q.front() / 100;
        int j = q.front() % 100;
        q.pop();

        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
            return false;
        }
        visited[i][j] = true;

        int moveI[] = {0, 0, 1, -1};
        int moveJ[] = {1, -1, 0, 0};

        for (int k = 0; k < 4; k++) {
            int a = i + moveI[k];
            int b = j + moveJ[k];

            if (a >= 0 && a < n && b >= 0 && b < m) {
                if (input[i][j] >= input[a][b]) {
                    if (!visited[a][b]) {
                        q.push(a * 100 + b);
                    }
                }
            }
        }
    }

    return true;
}

int run() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];
        }
    }

    bool filled[n][m] = {false};
    memset(source, -1, sizeof(source));
    memset(filled, false, sizeof(filled));
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            filled[i][j] = isFilled(i * 100 + j, n, m);
        }
    }

    memset(height, 0, sizeof(height));
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (filled[i][j]) {
                int min = INT_MAX;

                int p[100][100] = {-1};
                queue<int> q;
                q.push(i * 100 + j);
                bool visited[100][100] = {false};
                visited[i][j] = true;

                while (!q.empty()) {
                    int u = q.front() / 100;
                    int v = q.front() % 100;
                    q.pop();

                    int moveI[] = {0, 0, 1, -1};
                    int moveJ[] = {1, -1, 0, 0};

                    for (int k = 0; k < 4; k++) {
                        int a = u + moveI[k];
                        int b = v + moveJ[k];

                        if (a >= 0 && a < n && b >= 0 && b < m) {
                            if (filled[a][b]) {
                                if (!visited[a][b]) {
                                    q.push(a * 100 + b);
                                    visited[a][b] = true;
                                }
                            } else if (min > input[a][b]) {
                                min = input[a][b];
                            }
                        }
                    }
                }
                height[i][j] = min;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (filled[i][j]) {
                sum += height[i][j] - input[i][j];
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
