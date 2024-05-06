#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int t, k;
int a[505];
int sum[505];
int dp[505][505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> t;
    while(t--) {
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k - i; j++) {
                dp[j][j + i] = INF;
                for (int l = j; l < j + i; l++) {
                    dp[j][j + i] = min(dp[j][j + i], dp[j][l] + dp[l + 1][j + i] + sum[j + i] - sum[j - 1]);
                }
            }
        }

        cout << dp[1][k] << '\n';
    }
}