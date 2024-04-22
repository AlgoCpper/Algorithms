#include <bits/stdc++.h>
using namespace std;

int n;
int board[25][25];

void up(int arr[][25]) {
    for (int i = 0; i < n; i++) {
        deque<pair<int, bool>> dq;

        for (int j = 0; j < n; j++) {
            int val = arr[j][i];

            if (val == 0) continue;

            if (dq.empty()) {
                dq.push_back({ val, false });
                continue;
            }

            auto back = dq.back();
            if (val == back.first) {
                if (back.second) {
                    dq.push_back({ val, false });
                    continue;
                }
                dq.pop_back();
                dq.push_back({ val * 2, true });
            } else {
                dq.push_back({ val, false });
            }
        }

        for (int j = 0; j < n; j++) arr[j][i] = 0;

        for (int idx = 0; !dq.empty(); idx++) {
            arr[idx][i] = dq.front().first;
            dq.pop_front();
        }
    }
}

void down(int arr[][25]) {
    for (int i = 0; i < n; i++) {
        deque<pair<int, bool>> dq;

        for (int j = n - 1; j >= 0; j--) {
            int val = arr[j][i];

            if (val == 0) continue;

            if (dq.empty()) {
                dq.push_back({ val, false });
                continue;
            }

            auto back = dq.back();
            if (val == back.first) {
                if (back.second) {
                    dq.push_back({ val, false });
                    continue;
                }
                dq.pop_back();
                dq.push_back({ val * 2, true });
            } else {
                dq.push_back({ val, false });
            }
        }

        for (int j = 0; j < n; j++) arr[j][i] = 0;

        for (int idx = n - 1; !dq.empty(); idx--) {
            arr[idx][i] = dq.front().first;
            dq.pop_front();
        }
    }
}

void right(int arr[][25]) {
    for (int i = 0; i < n; i++) {
        deque<pair<int, bool>> dq;

        for (int j = n - 1; j >= 0; j--) {
            int val = arr[i][j];

            if (val == 0) continue;

            if (dq.empty()) {
                dq.push_back({ val, false });
                continue;
            }

            auto back = dq.back();
            if (val == back.first) {
                if (back.second) {
                    dq.push_back({ val, false });
                    continue;
                }
                dq.pop_back();
                dq.push_back({ val * 2, true });
            } else {
                dq.push_back({ val, false });
            }
        }

        for (int j = 0; j < n; j++) arr[i][j] = 0;

        for (int idx = n - 1; !dq.empty(); idx--) {
            arr[i][idx] = dq.front().first;
            dq.pop_front();
        }
    }
}

void left(int arr[][25]) {
    for (int i = 0; i < n; i++) {
        deque<pair<int, bool>> dq;

        for (int j = 0; j < n; j++) {
            int val = arr[i][j];

            if (val == 0) continue;

            if (dq.empty()) {
                dq.push_back({ val, false });
                continue;
            }

            auto back = dq.back();
            if (val == back.first) {
                if (back.second) {
                    dq.push_back({ val, false });
                    continue;
                }
                dq.pop_back();
                dq.push_back({ val * 2, true });
            } else {
                dq.push_back({ val, false });
            }
        }

        for (int j = 0; j < n; j++) arr[i][j] = 0;

        for (int idx = 0; !dq.empty(); idx++) {
            arr[i][idx] = dq.front().first;
            dq.pop_front();
        }
    }
}

void func(int dir, int arr[][25]) {
    if (dir == 0) up(arr);
    else if (dir == 1) down(arr);
    else if (dir == 2) right(arr);
    else left(arr);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int arr[25][25] = {};

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }

    int ans = 0;

    for (int num = 0; num < 1024; num++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) arr[i][j] = board[i][j];
        }

        int number = num;
        for (int i = 0; i < 5; i++) {
            func(number % 4, arr);
            number /= 4;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) ans = max(ans, arr[i][j]);
        }
    }

    cout << ans;
}