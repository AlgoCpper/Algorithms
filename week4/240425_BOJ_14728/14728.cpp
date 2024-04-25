#include <bits/stdc++.h>
using namespace std;

int n, t;
int w[1004];
int v[1004];
int d[10004];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

    for (int i = 0; i < n; i++) {
        for (int j = t; j > 0; j--) {
            if (w[i] <= j) {
                d[j] = max(d[j], d[j - w[i]] + v[i]);
            }
        }
    }

    cout << d[t];
}