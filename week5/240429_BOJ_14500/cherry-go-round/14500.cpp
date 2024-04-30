#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[505][505];

pair<int, int> directions[19][4] = {
    { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } },
    { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } },

    { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } },

    { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, 1 } },
    { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 } },
    { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 }, { 1, -2 } },

    { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, -1 } },
    { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 } },
    { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 2, 0 } },
    { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 2 } },

    { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 1 } },
    { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, -1 } },

    { { 0, 0 }, { 1, 0 }, { 1, -1 }, { 2, -1 } },
    { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } },

    { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 }, { 2, 0 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 }, { 1, 1 } },
    { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 0 } }
};

bool oob(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

bool oob(int x, int y, int i) {
    for (int dir = 0; dir < 4; dir++) {
        auto p = directions[i][dir];
        if (oob(x + p.first, y + p.second)) return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }

    int mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int tet = 0; tet < 19; tet++) {
                if (oob(i, j, tet)) continue;

                int temp = 0;
                for (int dir = 0; dir < 4; dir++) {
                    auto p = directions[tet][dir];
                    int nx = i + p.first;
                    int ny = j + p.second;

                    temp += board[nx][ny];
                }
                mx = max(mx, temp);
            }
        }
    }

    cout << mx;
}