#include <bits/stdc++.h>
using namespace std;

string s;

bool lucky() {
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> s;
    sort(s.begin(), s.end());
    
    int cnt = 0;

    while(1) {
        if (lucky()) cnt++;
        if (!next_permutation(s.begin(), s.end())) break;
    }

    cout << cnt;
}