#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[55][55];
int origin[55][55];
int rotated[55][55];
int operations[10][3];

void rotate(int r, int c, int s) {
    for (int i = s; i > 0; i--) {
        for (int j = r - i; j <= r + i; j++) {
            rotated[j][c - i] = a[j + 1][c - i];
            rotated[j][c + i] = a[j - 1][c + i];
        }
        for (int j = c - i; j <= c + i; j++) {
            rotated[r - i][j] = a[r - i][j - 1];
            rotated[r + i][j] = a[r + i][j + 1];
        }
        rotated[r - i][c - i] = a[r - i + 1][c - i];
        rotated[r - i][c + i] = a[r - i][c + i - 1];
        rotated[r + i][c - i] = a[r + i][c - i + 1];
        rotated[r + i][c + i] = a[r + i - 1][c + i];
    }
    rotated[r][c] = a[r][c];

    for (int i = r - s; i <= r + s; i++) {
        for (int j = c - s; j <= c + s; j++) a[i][j] = rotated[i][j];
    }
}

int factorial(int num) {
    int result = 1;
    while (num > 0) {
        result *= num--;
    }
    return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            origin[i][j] = a[i][j];
        }
    }

    vector<int> order;

    for (int i = 0; i < k; i++) {
        int r, c, s;
        cin >> r >> c >> s;

        operations[i][0] = r - 1;
        operations[i][1] = c - 1;
        operations[i][2] = s;
        order.push_back(i);
    }

    int mn = 100000;
    for (int i = factorial(k); i > 0; i--) {
        for (int rot : order) {
            rotate(operations[rot][0], operations[rot][1], operations[rot][2]);
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) sum += a[i][j];
            mn = min(mn, sum);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = origin[i][j];
            }
        }
        next_permutation(order.begin(), order.end());
    }

    cout << mn;
}