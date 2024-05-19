#include <bits/stdc++.h>
using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int n, m;
char board[22][22];
bool vis[22][22][22][22];
pair<int, int> coin1Pos = { -1, -1 };
pair<int, int> coin2Pos = { -1, -1 };

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'o') {
                if (coin1Pos.first == -1 && coin1Pos.second == -1) coin1Pos = { i, j };
                else coin2Pos = { i, j }; 
            }
        }
    }

    queue<tuple<pair<int, int>, pair<int, int>, int>> q;

    vis[coin1Pos.first][coin1Pos.second][coin2Pos.first][coin2Pos.second] = 1;

    q.push(make_tuple(coin1Pos, coin2Pos, 0));

    while(!q.empty()) {
        auto p = q.front(); q.pop();

        pair<int, int> p1 = get<0>(p);
        pair<int, int> p2 = get<1>(p);

        int x1 = p1.first;
        int y1 = p1.second;
        int x2 = p2.first;
        int y2 = p2.second;
        int moves = get<2>(p);

        if (moves == 10) {
            cout << -1;
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx1 = x1 + dx[dir];
            int ny1 = y1 + dy[dir];
            int nx2 = x2 + dx[dir];
            int ny2 = y2 + dy[dir];

            if ((oob(nx1, ny1) && oob(nx2, ny2))) continue;

            if (oob(nx1, ny1) || oob(nx2, ny2)) {
                cout << moves + 1;
                return 0;
            }

            if (vis[nx1][ny1][nx2][ny2]) continue;

            if (board[nx1][ny1] == '#') {
                nx1 = x1;
                ny1 = y1;
            }

            if (board[nx2][ny2] == '#') {
                nx2 = x2;
                ny2 = y2;
            }

            vis[nx1][ny1][nx2][ny2] = 1;
            q.push(make_tuple(make_pair(nx1, ny1), make_pair(nx2, ny2), moves + 1));
        }
    }

    cout << -1;
}