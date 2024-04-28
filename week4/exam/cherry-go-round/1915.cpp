#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[1004];
int d[1004][1004];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i - 1][j - 1] == '0') continue;
            d[i][j] = min({ d[i - 1][j - 1], d[i - 1][j], d[i][j - 1] }) + 1;
        }
    }
    int len = *max_element(&d[1][1], &d[n][m]);
    cout << len * len;
}