#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int papers[5] = { 5, 5, 5, 5, 5 };
int ans;

bool can1(int x, int y) {
    return board[x][y];
}

bool can2(int x, int y) {
    if (x + 1 >= 10 || y + 1 >= 10) return false;
    return board[x][y] && board[x + 1][y] && board[x][y + 1] && board[x + 1][y + 1];
}

bool can3(int x, int y) {
    if (x + 2 >= 10 || y + 2 >= 10) return false;
    return board[x][y] && board[x + 1][y] && board[x][y + 1] && board[x + 1][y + 1]
    && board[x + 2][y] && board[x + 2][y + 1] && board[x + 2][y + 2] && board[x][y + 2] && board[x + 1][y + 2];
}

bool can4(int x, int y) {
    if (x + 3 >= 10 || y + 3 >= 10) return false;
    return board[x][y] && board[x + 1][y] && board[x][y + 1] && board[x + 1][y + 1]
    && board[x + 2][y] && board[x + 2][y + 1] && board[x + 2][y + 2] && board[x][y + 2] && board[x + 1][y + 2]
    && board[x + 3][y] && board[x + 3][y + 1] && board[x + 3][y + 2] && board[x + 3][y + 3] && board[x][y + 3] && board[x + 1][y + 3] && board[x + 2][y + 3];
}

bool can5(int x, int y) {
    if (x + 4 >= 10 || y + 4 >= 10) return false;
    return board[x][y] && board[x + 1][y] && board[x][y + 1] && board[x + 1][y + 1]
    && board[x + 2][y] && board[x + 2][y + 1] && board[x + 2][y + 2] && board[x][y + 2] && board[x + 1][y + 2]
    && board[x + 3][y] && board[x + 3][y + 1] && board[x + 3][y + 2] && board[x + 3][y + 3] && board[x][y + 3] && board[x + 1][y + 3] && board[x + 2][y + 3]
    && board[x + 4][y] && board[x + 4][y + 1] && board[x + 4][y + 2] && board[x + 4][y + 3] && board[x + 4][y + 4] && board[x][y + 4] && board[x + 1][y + 4] && board[x + 2][y + 4] && board[x + 3][y + 4];
}

bool has1() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == 1) return true;
        }
    }

    return false;
}

int func(int x, int y, int cnt) {
    if (x == 10 && y == 0) {
        if (has1()) return -1;
        else return cnt;
    }

    if (board[x][y] == 0) {
        if (y + 1 >= 10) return func(x + 1, 0, cnt);
        else return func(x, y + 1, cnt);
    }

    int mn = 0x3f3f3f3f;

    if (can5(x, y) && papers[4] > 0) {
        for (int i = x; i <= x + 4; i++) {
            for (int j = y; j <= y + 4; j++) board[i][j] = 0;
        }
        papers[4]--;

        int changed = y + 1 >= 10 ? func(x + 1, 0, cnt + 1) : func(x, y + 1, cnt + 1);

        if (changed != -1) mn = min(mn, changed);

        for (int i = x; i <= x + 4; i++) {
            for (int j = y; j <= y + 4; j++) board[i][j] = 1;
        }
        papers[4]++;
    }

    if (can4(x, y) && papers[3] > 0) {
        for (int i = x; i <= x + 3; i++) {
            for (int j = y; j <= y + 3; j++) board[i][j] = 0;
        }
        papers[3]--;

        int changed = y + 1 >= 10 ? func(x + 1, 0, cnt + 1) : func(x, y + 1, cnt + 1);

        if (changed != -1) mn = min(mn, changed);

        for (int i = x; i <= x + 3; i++) {
            for (int j = y; j <= y + 3; j++) board[i][j] = 1;
        }
        papers[3]++;
    }

    if (can3(x, y) && papers[2] > 0) {
        for (int i = x; i <= x + 2; i++) {
            for (int j = y; j <= y + 2; j++) board[i][j] = 0;
        }
        papers[2]--;

        int changed = y + 1 >= 10 ? func(x + 1, 0, cnt + 1) : func(x, y + 1, cnt + 1);

        if (changed != -1) mn = min(mn, changed);

        for (int i = x; i <= x + 2; i++) {
            for (int j = y; j <= y + 2; j++) board[i][j] = 1;
        }
        papers[2]++;
    }

    if (can2(x, y) && papers[1] > 0) {
        for (int i = x; i <= x + 1; i++) {
            for (int j = y; j <= y + 1; j++) board[i][j] = 0;
        }
        papers[1]--;

        int changed = y + 1 >= 10 ? func(x + 1, 0, cnt + 1) : func(x, y + 1, cnt + 1);

        if (changed != -1) mn = min(mn, changed);

        for (int i = x; i <= x + 1; i++) {
            for (int j = y; j <= y + 1; j++) board[i][j] = 1;
        }
        papers[1]++;
    }

    if (can1(x, y) && papers[0] > 0) {
        board[x][y] = 0;
        papers[0]--;

        int changed = y + 1 >= 10 ? func(x + 1, 0, cnt + 1) : func(x, y + 1, cnt + 1);

        if (changed != -1) mn = min(mn, changed);

        board[x][y] = 1;
        papers[0]++;
    }

    if (mn == 0x3f3f3f3f) return - 1;
    return mn;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) cin >> board[i][j];
    }

    cout << func(0, 0, 0);
}