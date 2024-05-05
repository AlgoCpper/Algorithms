#include <bits/stdc++.h>
using namespace std;

int m, n;
int l[1000005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> m >> n;

    int snack = 0;

    for (int i = 0; i < n; i++) {
        cin >> l[i];
        snack += l[i];
    }

    if (snack < m) {
        cout << 0;
        return 0;
    }

    sort(l, l + n, greater<int>());
  
    int left = 1;
    int right = l[0];

    while (left <= right) {
        int mid = (left + right) / 2;
        
        snack = 0;

        for (int i = 0; i < n; i++) {
            snack += l[i] / mid;
        }

        if (snack < m) right = mid - 1;
        else left = mid + 1;
    }

    cout << left - 1;
}