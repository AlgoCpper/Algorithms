#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
    }

    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a + b;

        ans += c;
        pq.push(c);
    }

    cout << ans;
}