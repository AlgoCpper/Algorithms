#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int d;
string str;
ll x, y;

pair<ll, ll> expToCoor(int depth, ll sx, ll ex, ll sy, ll ey) {

    if (depth == d) {
        return { sx, sy };
    }

    char c = str[depth];

    if (c == '1') {
        return expToCoor(depth + 1, sx, (sx + ex) / 2, (sy + ey) / 2 + 1, ey);
    }

    if (c == '2') {
        return expToCoor(depth + 1, sx, (sx + ex) / 2, sy, (sy + ey) / 2);
    }

    if (c == '3') {
        return expToCoor(depth + 1, (sx + ex) / 2 + 1, ex, sy, (sy + ey) / 2);
        
    }

    return expToCoor(depth + 1, (sx + ex) / 2 + 1, ex, (sy + ey) / 2 + 1, ey);
}

string coorToExp(string s, pair<ll, ll> coor, int depth, ll sx, ll ex, ll sy, ll ey) {
    
    if (depth == d) {
        return s;
    }

    if (coor.first <= (sx + ex) / 2 && coor.second > (sy + ey) / 2) {
        return coorToExp(s + "1", coor, depth + 1, sx, (sx + ex) / 2, (sy + ey) / 2 + 1, ey);
    }

    if (coor.first <= (sx + ex) / 2 && coor.second <= (sy + ey) / 2) {
        return coorToExp(s + "2", coor, depth + 1, sx, (sx + ex) / 2, sy, (sy + ey) / 2);
    }

    if (coor.first > (sx + ex) / 2 && coor.second <= (sy + ey) / 2) {
        return coorToExp(s + "3", coor, depth + 1, (sx + ex) / 2 + 1, ex, sy, (sy + ey) / 2);
    }

    return coorToExp(s + "4", coor, depth + 1, (sx + ex) / 2 + 1, ex, (sy + ey) / 2 + 1, ey);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> d >> str >> x >> y;

    pair<ll, ll> coor = expToCoor(0, 0, (1ll << d) - 1, 0, (1ll << d) - 1);
    
    ll nx = coor.first - y;
    ll ny = coor.second + x;

    if (nx < 0 || nx >= (1ll << d) || ny < 0 || ny >= (1ll << d)) {
        cout << -1;
        return 0;
    }

    cout <<  coorToExp("", { nx, ny }, 0, 0, (1ll << d) - 1, 0, (1ll << d) - 1);
}