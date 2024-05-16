#include <bits/stdc++.h>
using namespace std;

int n;
char ans[7][100];

void func(int st, int en, int level) {
    if (level == n || st == en) return;

    int mid = (st + en) / 2;

    for (int i = st; i <= mid; i++) ans[level][i] = 'A';
    for (int i = mid + 1; i <= en; i++) ans[level][i] = 'B';
    
    func(st, mid, level + 1);
    func(mid + 1, en, level + 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) ans[i][j] = 'A';
            else ans[i][j] = 'B';
        }
    }

    func(0, n - 1, 0);

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}