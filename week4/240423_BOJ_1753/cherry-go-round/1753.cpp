#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int v, e;
int k;
vector<pair<int, int>> adj[20005];
int d[20005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	cin >> k;

	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({ w, v });
	}

	fill(d, d + v + 1, INF); // 1-indexed

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, k });
	d[k] = 0;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int weight = cur.first;
		int node = cur.second;

		if (d[node] != weight) continue;

		for (auto nxt : adj[node]) {
			if (d[nxt.second] <= d[node] + nxt.first) continue;

			d[nxt.second] = d[node] + nxt.first;
			pq.push({ d[nxt.second], nxt.second });
		}
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF";
		else cout << d[i];
		cout << '\n';
	}
}
