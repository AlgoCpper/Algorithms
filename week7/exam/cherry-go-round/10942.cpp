#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2002];
int pal[2002][2002];
int m;

int isPal(int st, int en) {
    if (pal[st][en] != -1) return pal[st][en];
    if (st == en) return pal[st][en] = 1;

    if (st + 1 > en - 1) return pal[st][en] = (arr[st] == arr[en]);
    return pal[st][en] = isPal(st + 1, en - 1) && (arr[st] == arr[en]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    fill(&pal[1][1], &pal[n][n + 1], -1);
    
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << isPal(s, e) << '\n';
    }
}