#include <bits/stdc++.h>
using namespace std;

int t;
pair<int, int> a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int doc, itv;
            cin >> doc >> itv;
            a[i] = { doc, itv };
        }

        sort(a, a + n);

        int mn = a[0].second;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (a[i].second <= mn) {
                cnt++;
                mn = a[i].second;
            }
        }
        cout << cnt << '\n';
    }
}