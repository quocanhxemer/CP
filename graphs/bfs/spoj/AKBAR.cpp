#include <bits/stdc++.h>

using namespace std;

void run() {
    int N, R, M;
    cin >> N >> R >> M;

    vector<int> graph[N + 1];
    for (int i = 1; i <= R; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int visited[N + 1] = {0};
    for (int i = 1; i <= M; i++) {
        int node, strength;
        cin >> node >> strength;

        int d[N + 1];

        queue<int> q;
        q.push(node);

        if (visited[node]) {
            cout << "No\n";
            return;
        }

        visited[node] = node;
        d[node] = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (d[current] < strength) {
                for (int neighbor : graph[current]) {
                    if (!visited[neighbor]) {
                        d[neighbor] = d[current] + 1;
                        visited[neighbor] = node;
                        q.push(neighbor);
                    } else if (visited[neighbor] != node) {
                        cout << "No\n";
                        return;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        run();
    }
}
