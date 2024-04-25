#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
vector<pair<int, int>> chose;

int chickensSize;
int ans = 100000000;

void func(int depth, int st) {
    if (depth == m) {
        int sum = 0;
        for(auto house : houses) {
            int dist = 1000000;
            for (auto ch : chose) {
                int dx = abs(ch.first - house.first);
                int dy = abs(ch.second - house.second);
                dist = min(dist, dx + dy);
            }
            sum += dist;
        }
        ans = min(ans, sum);
        return;
    }

    for (int i = st; i < chickensSize; i++) {
        chose.push_back(chickens[i]);
        func(depth + 1, i + 1);

        chose.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            if (input == 1) houses.push_back({ i, j });
            else if (input == 2) chickens.push_back({ i, j });
        }
    }

    chickensSize = chickens.size();

    func(0, 0);
    cout << ans;
}