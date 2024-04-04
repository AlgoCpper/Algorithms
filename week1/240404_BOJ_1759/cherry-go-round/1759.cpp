#include <bits/stdc++.h>
using namespace std;

int l, c;
char s[20];
vector<char> v;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void func(int depth, int st) {
    if (depth == l) {
        int vowel = 0;
        int consonant = 0;

        for (char c : v) {
            if (isVowel(c)) vowel++;
            else consonant++;
        }

        if (vowel < 1 || consonant < 2) return;
        for (char c : v) cout << c;
        cout << '\n';
    }

    for (int i = st; i < c; i++) {
        v.push_back(s[i]);
        func(depth + 1, i + 1);
        v.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> l >> c;

    for (int i = 0; i < c; i++) cin >> s[i];
    sort(s, s + c);
    func(0, 0);
}