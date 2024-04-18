#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> coord;

int board[9][9];
vector<coord> zeros;
int zerosSize;
bool finish;

bool candidateRect(coord leftUp, int num) {
    int x = leftUp.first;
    int y = leftUp.second;

    bool used[10] = {};

    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            int nx = x + dx;
            int ny = y + dy;

            if (num == board[nx][ny]) return false;
        }
    }

    return true;
}

bool candidateV(coord pos, int num) {
    int y = pos.second;

    bool used[10] = {};

    for (int x = 0; x < 9; x++) {
        if (num == board[x][y]) return false;
    }

    return true;    
}

bool candidateH(coord pos, int num) {
    int x = pos.first;

    bool used[10] = {};

    for (int y = 0; y < 9; y++) {
        if (num == board[x][y]) return false;
    }

    return true;
}

void solve(int depth) {
    if (finish) return;

    if (depth == zerosSize) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        finish = true;
        return;
    }

    coord pos = zeros[depth];
    int x = pos.first;
    int y = pos.second;

    for (int i = 1; i <= 9; i++) {
        if (!candidateRect({ (x / 3) * 3, (y / 3) * 3 }, i)) continue;
        if (!candidateV(pos, i)) continue;
        if (!candidateH(pos, i)) continue;

        board[x][y] = i;
        solve(depth + 1);
        board[x][y] = 0;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) zeros.push_back({ i, j });
        }
    }

    zerosSize = zeros.size();
    solve(0);
}
