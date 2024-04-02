#include <bits/stdc++.h>
using namespace std;

string s;
stack<pair<char, int>> st;
int flag;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    
    cin >> s;

    for (char c : s) {

        if (st.empty()) {
            st.push( { c, 1 } );
            continue;
        }

        int level = st.top().second;

        if (level == 3 && st.top().first == 'A') {

            if (c != 'P') {
                cout << "NP";
                return 0;
            }

            st.pop();
            st.pop();
            continue;
        }

        if (level == 2) {
            if (c == 'A') {
                st.push( { c, 3 } );
                continue;
            }
            st.push( { c, 2 } );
            continue;
        }

        if (level == 1) {
            if (c == 'A') {
                cout << "NP";
                return 0;
            }
            st.push( { c, 2 } );
        }
    }

    if (st.size() == 1 && st.top().first == 'P') {
        cout << "PPAP";
        return 0;
    }

    cout << "NP";
}