#include <bits/stdc++.h>
using namespace std;

int n;
char board[8][8];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

bool success(int x, int y) {
    for (int dir = 0; dir < 4; dir++) {
        int nx = x;
        int ny = y;

        while(!oob(nx + dx[dir], ny + dy[dir])) {
            nx += dx[dir];
            ny += dy[dir];

            if (board[nx][ny] == 'O') break;
            if (board[nx][ny] == 'S') return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    vector<pair<int, int>> t;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'T') t.push_back({ i, j });
        }
    }

    for (int a = 0; a < n * n; a++) {
        for (int b = a + 1; b < n * n; b++) {
            for (int c = b + 1; c < n * n; c++) {
                int ax = a / n;
                int ay = a % n;

                int bx = b / n;
                int by = b % n;
                
                int cx = c / n;
                int cy = c % n;

                if (board[ax][ay] != 'X') continue;
                if (board[bx][by] != 'X') continue;
                if (board[cx][cy] != 'X') continue;

                board[ax][ay] = 'O';
                board[bx][by] = 'O';
                board[cx][cy] = 'O';

                bool flag = true;
                for (auto p : t) {
                    if (!success(p.first, p.second)) flag = false;
                }

                if (flag) {
                    cout << "YES";
                    return 0;
                }

                board[ax][ay] = 'X';
                board[bx][by] = 'X';
                board[cx][cy] = 'X';
            }
        }
    }

    cout << "NO";
}