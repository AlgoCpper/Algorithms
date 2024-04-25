#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];
int l;
int r;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r += a[i];
        l = max(l, a[i]);
    }

    while(l <= r) {
        int sum = 0;
        int cnt = 0;
        int mid = (l + r) / 2;

        for (int i = 0; i < n; i++) {
            if (sum + a[i] > mid) {
                sum = 0;
                cnt++;
            }
            sum += a[i];
        }

        if (sum != 0) cnt++;

        if (cnt <= m) r = mid - 1;
        else l = mid + 1;
    }

    cout << l;
}