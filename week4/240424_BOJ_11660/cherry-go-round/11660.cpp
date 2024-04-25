#include <bits/stdc++.h>
using namespace std;

int a[1030][1030];
int d[1030][1030];
int n, m;
int xa, ya, xb, yb;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) d[i][j] = d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1] + a[i][j];
    }

    while(m--) {
        cin >> xa >> ya >> xb >> yb;
        
        xa--;
        ya--;

        cout << d[xb][yb] - d[xb][ya] - d[xa][yb] + d[xa][ya] << '\n';
    }
}