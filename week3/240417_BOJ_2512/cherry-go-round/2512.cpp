#include <bits/stdc++.h>
using namespace std;

int a[10005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;

    int mn = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = max(mn, a[i]);
    }

    int m;
    cin >> m;

    int l = 1;
    int r = mn;

    while(l <= r) {
        int mid = (l + r) / 2;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= mid) sum += a[i];
            else sum += mid;
        }

        if (sum <= m) l = mid + 1;
        else r = mid - 1;
    }

    cout << r;
}