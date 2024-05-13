#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[100005];
int st, en, sum;
int ans = 100001;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> s;

    for (int i = 0; i < n; i++) cin >> a[i];

    sum = a[0];

    while (st < n) {
        if (en == n) break;

        if (sum < s) {
            sum += a[++en];
            continue;
        }

        ans = min(ans, en - st + 1);
        sum -= a[st++];
    }

    if (ans == 100001) ans = 0;

    cout << ans;
}