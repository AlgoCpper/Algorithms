#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n;
int board[130][130];
int d[130][130];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int p = 1;;p++) {
		cin >> n;
		if (n == 0) return 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cin >> board[i][j];
		}

		fill(&d[0][0], &d[n - 1][n], INF);

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		
		pq.push({ board[0][0], {0, 0}});
		d[0][0] = board[0][0];

		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			int dist = cur.first;
			int x = cur.second.first;
			int y = cur.second.second;

			if (d[x][y] != dist) continue;

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

				if (d[nx][ny] <= d[x][y] + board[nx][ny]) continue;
				d[nx][ny] = d[x][y] + board[nx][ny];
				pq.push({ d[nx][ny], { nx, ny } });
			}
		}

		cout << "Problem " << p << ": " << d[n - 1][n - 1] << '\n';
	}
}
