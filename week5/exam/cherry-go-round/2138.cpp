#include <bits/stdc++.h>
using namespace std;

int n;
string goal;
string candidate;
string challenge;
int ans = 111111;

void pushButton(int idx) {
    challenge[idx] = '1' - challenge[idx] + '0';
    if (idx > 0) challenge[idx - 1] = '1' - challenge[idx - 1] + '0';
    if (idx < n - 1) challenge[idx + 1] = '1' - challenge[idx + 1] + '0';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> goal >> candidate;

    challenge = candidate;
    pushButton(0);
    int cnt = 1;

    for (int i = 1; i < n; i++) {
        if (goal[i - 1] != challenge[i - 1]) {
            pushButton(i);
            cnt++;
        }
    }

    if (goal == challenge) ans = cnt;

    challenge = candidate;
    cnt = 0;

    for (int i = 1; i < n; i++) {
        if (goal[i - 1] != challenge[i - 1]) {
            pushButton(i);
            cnt++;
        }
    }

    if (goal == challenge) ans = min(ans, cnt);
    
    if (ans != 111111) cout << ans;
    else cout << -1;
}