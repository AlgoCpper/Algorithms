#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> s >> t;
    
    queue<string> q;
    q.push(t);

    while(!q.empty()) {
        string cur = q.front();
        q.pop();

        if (cur == s) {
            cout << 1;
            return 0;
        }

        int len = cur.length();

        if (len < s.length()) {
            cout << 0;
            return 0;
        }

        if (cur[len - 1] == 'A') {
            q.push(cur.substr(0, len - 1));
        }

        if (cur[0] == 'B') {
            string withoutB = cur.substr(1, len - 1);
            reverse(withoutB.begin(), withoutB.end());
            q.push(withoutB);
        }
    }

    cout << 0;
}