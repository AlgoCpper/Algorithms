#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10003];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    int st = 0;
    int en = 0;
    int sum = a[0];
    int cnt = 0;
    
    while(en < n) {
        if (sum < m) {
            sum += a[++en];
            continue;
        }

        if (sum > m) {
            sum -= a[st++];
            continue;
        }

        cnt++;
        sum += a[++en];
        continue;
    }

    cout << cnt;
}