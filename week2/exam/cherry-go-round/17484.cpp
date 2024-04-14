#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[10][10];
int dx[3] = { -1, -1, -1 };
int dy[3] = { -1, 0, 1 };
int d[10][10][3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) cin >> board[i][j];
    }

    for (int j = 0; j < m; j++) {
        for (int k = 0; k < 3; k++) {
            d[0][j][k] = board[0][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 3; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m) {
                    d[i][j][k] = 10000000;
                    continue;
                }

                int mn = 10000000;
                for (int dir = 0; dir < 3; dir++) {
                    if (dir == k) continue;
                    mn = min(mn, d[x][y][dir]);
                }
                d[i][j][k] = board[i][j] + mn;
            }
        }
    }

    cout << *min_element(&d[n - 1][0][0], &d[n - 1][m - 1][2]);
}