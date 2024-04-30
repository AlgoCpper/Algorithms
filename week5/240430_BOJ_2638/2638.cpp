#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[105][105];
int ans;
queue<pair<int, int>> q;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
const int AIR = 8;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }

    board[0][0] = AIR;
    q.push({ 0, 0 });

    while(1) {

        while(!q.empty()) {
            auto p = q.front(); q.pop();
            int x = p.first;
            int y = p.second;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] != 0) continue;
                board[nx][ny] = AIR;
                q.push({ nx, ny });
            }
        }

        int cheese = 0;
        queue<pair<int, int>> melting;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 1) continue;
                cheese++;

                int air = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                    if (board[nx][ny] == AIR) air++;
                }

                if (air >= 2) melting.push({ i, j });
            }
        }

        if (cheese == 0) break;
        ans++;

        while(!melting.empty()) {
            auto p = melting.front(); melting.pop();
            board[p.first][p.second] = AIR;
            q.push({ p.first, p.second });
        }
    }
    cout << ans;
}