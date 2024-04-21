#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int arr[30003];
bool ate[3003];
int ans = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int dup = 0;
        int coupon = 1;

        for (int j = i; j < i + k; j++) {
            if (ate[arr[j % n]]) dup++;
            else ate[arr[j % n]] = true;

            if (arr[j % n] == c) coupon = 0;
        }

        ans = max(ans, k - dup + coupon);
        fill(ate, ate + d + 1, false);
    }

    cout << ans;
}