// https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>

using namespace std;

vector<int> graph[64];

int ptoi(int i, int j) {
    return (i - 'a') * 8 + (j - '1');
}

int run() {
    string a, b;
    cin >> a >> b;
    int start = ptoi(a[0], a[1]);
    int end = ptoi(b[0], b[1]);

    if (start == end) {
        return 0;
    }

    queue<int> q;
    q.push(start);

    int d[64];
    int visited[64] = {0};

    d[start] = 0;
    visited[start] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (!visited[v]) {
                d[v] = d[u] + 1;
                visited[v] = 1;
                q.push(v);

                if (v == end) {
                    return d[v];
                }
            }
        }
    }

    return -1;
}

void connect(int i1, int j1, int i2, int j2) {
    graph[ptoi(i1, j1)].push_back(ptoi(i2, j2));
    graph[ptoi(i2, j2)].push_back(ptoi(i1, j1));
}

int main() {
    for (int i = 'a'; i <= 'h'; i++) {
        for (int j = '1'; j <= '8'; j++) {
            if (i + 2 <= 'h') {
                if (j + 1 <= '8') {
                    connect(i, j, i + 2, j + 1);
                }
                if (j - 1 >= '1') {
                    connect(i, j, i + 2, j - 1);
                }
            }

            if (i + 1 <= 'h') {
                if (j + 2 <= '8') {
                    connect(i, j, i + 1, j + 2);
                }
                if (j - 2 >= '1') {
                    connect(i, j, i + 1, j - 2);
                }
            }
        }
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << run() << endl;
    }
}
