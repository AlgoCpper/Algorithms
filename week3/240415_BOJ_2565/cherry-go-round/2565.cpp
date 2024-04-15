#include <bits/stdc++.h>
using namespace std;

pair<int, int> wires[105];
int lis[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        wires[i] = { a, b };
    }

    sort(wires, wires + n);

    for (int i = 0; i < n; i++) {
        lis[i] = 1;

        for (int j = 0; j < i; j++) {
            if (wires[j].second < wires[i].second) {
                lis[i] = max(lis[j] + 1, lis[i]);
            }
        }
    }

    cout << n - *max_element(lis, lis + n);
}