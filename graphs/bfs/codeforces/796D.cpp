// https://codeforces.com/problemset/problem/796/D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    int police[k];
    for (int i = 0; i < k; i++) {
        cin >> police[i];
    }

    // graph[i] = {neighbor[i], edgeindex[i]}
    vector<pair<int, int>> graph[n + 1];
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }

    int visited[n + 1];
    int edges_used[n];
    memset(visited, 0, sizeof(visited));
    memset(edges_used, 0, sizeof(edges_used));

    queue<int> q;
    for (int i : police) {
        q.push(i);
        visited[i] = 1;
    }

    int edges_to_remove = n - 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (pair<int, int> v : graph[u]) {
            if (visited[v.first]) {
                continue;
            }

            q.push(v.first);
            visited[v.first] = 1;
            edges_used[v.second] = 1;
            edges_to_remove--;
        }
    }

    cout << edges_to_remove << endl;
    for (int i = 1; i <= n - 1; i++) {
        if (!edges_used[i]) {
            cout << i << " ";
        }
    }
}
