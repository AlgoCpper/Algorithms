#include <bits/stdc++.h>
using namespace std;

int h, w;
int arr[505];
int l[505];
int r[505];
int ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> h >> w;

    for (int i = 0; i < w; i++) cin >> arr[i];

    l[0] = arr[0];
    for (int i = 1; i < w; i++) l[i] = max(l[i - 1], arr[i]);

    r[w - 1] = arr[w - 1];
    for (int i = w - 2; i >= 0; i--) r[i] = max(r[i + 1], arr[i]);

    for (int i = 0; i < w; i++) ans += min(r[i], l[i]) - arr[i];

    cout << ans;
}