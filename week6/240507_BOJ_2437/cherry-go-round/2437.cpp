#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int ans = 1;

    for (int i = 0; i < n; i++) {
        if (ans < a[i]) break;
        
        ans += a[i];
    }

    cout << ans;
}