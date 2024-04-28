#include <bits/stdc++.h>
using namespace std;

int n, k;

int arr[10005];
int diff[10005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++) diff[i] = arr[i + 1] - arr[i];

    sort(diff, diff + n - 1);

    int ans = 0;
    for (int i = 0; i < n - 1 - (k - 1); i++) ans += diff[i];
    cout << ans;
}