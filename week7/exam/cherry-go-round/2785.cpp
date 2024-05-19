#include <bits/stdc++.h>
using namespace std;

int n, l;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    deque<int> dq;

    for (int i = 0; i < n; i++) { 
        int num;
        cin >> num;
        dq.push_back(num);
    }

    sort(dq.begin(), dq.end());

    int cnt = 0;

    while (dq.size() > 1) {
        dq.pop_back();
        dq.front()--;
        cnt++;

        if (dq.front() == 0) dq.pop_front();
    }

    cout << cnt;
}