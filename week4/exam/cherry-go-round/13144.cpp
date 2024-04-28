#include <bits/stdc++.h>
using namespace std;

int n;
int a[100003];
bool vis[100003];
int p1, p2;
long long ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int p1 = 0; p1 < n; p1++) {
        while (p2 < n) {
            if (vis[a[p2]]) break;
            vis[a[p2]] = 1;
            p2++;
        }
        ans += (p2 - p1);
        vis[a[p1]] = 0;
    }

    cout << ans << '\n';
}