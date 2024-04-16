#include <bits/stdc++.h>
using namespace std;

pair<int, int> info[10005];
bool schedule[10005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int p , d;
        cin >> p >> d;

        info[i] = { p, d };
    }

    sort(info, info + n,
    [&](pair<int, int> p1, pair<int, int> p2) {
        return p1.first > p2.first;
        }
    );

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int pay = info[i].first;
        int day = info[i].second;

        for (int d = day; d >= 1; d--) {
            if (!schedule[d]) {
                schedule[d] = true;
                ans += pay;
                break;
            }
        }
    }

    cout << ans;
}
