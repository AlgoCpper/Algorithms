#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int l[1005];
int r[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        l[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && l[i] < l[j] + 1) l[i] = l[j] + 1;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        r[i] = 1;
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[i] && r[i] < r[j] + 1) r[i] = r[j] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max( ans, l[i] + r[i] - 1);
    }

    cout << ans;
}