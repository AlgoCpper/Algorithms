#include <bits/stdc++.h>
using namespace std;

int k;
int v, e;
vector<int> adj[20005];
int color[20005];
bool no;

void bfs(int st) {
    queue<int> q;

    q.push(st);
    color[st] = 1;

    while (!q.empty()) {
        int vertex = q.front(); q.pop();

        for (int next : adj[vertex]) {
            if (color[next] != 0) continue;

            color[next] = -color[vertex];
            q.push(next);
        }
    }
}

bool isBi() {
    for (int i = 1; i <= v; i++) {
        int nodeColor = color[i];
        for (int nxt : adj[i]) {
            if (color[nxt] == nodeColor) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> k;
    while (k--) {
        cin >> v >> e;
        
        fill(adj, adj + 1 + v, vector<int>(0));
        fill(color, color + 1 + v, 0);
        no = false;

        for (int i = 0 ; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1 ; i <= v; i++) {
            if (color[i] != 0) continue;
            bfs(i);
        }

        if (isBi()) cout << "YES\n";
        else cout << "NO\n";
    }
}