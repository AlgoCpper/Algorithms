#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int maxLeft[1005];
int maxRight[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;

    int st = 10004;
    int en = 0;

    while (n--) {
        int l, h;
        cin >> l >> h;

        a[l] = h;
        st = min(st, l);
        en = max(en, l);
    }

    int lm = 0;
    for (int i = st; i <= en; i++) {
        lm = max(lm, a[i]);
        maxLeft[i] = lm;
    }

    int rm = 0;
    for (int i = en; i >= st; i--) {
        rm = max(rm, a[i]);
        maxRight[i] = rm;
    }

    int ans = 0;
    for (int i = st; i <= en; i++) {
        ans += min(maxLeft[i], maxRight[i]);
    }

    cout << ans;
}