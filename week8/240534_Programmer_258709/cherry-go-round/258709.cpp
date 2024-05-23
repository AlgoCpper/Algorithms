#include <bits/stdc++.h>

using namespace std;

auto cmp = [](pair<int, vector<int>> p1, pair<int, vector<int>> p2) {
    return p1.first < p2.first;
};

vector<int> solution(vector<vector<int>> dice) {
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(cmp)> rank(cmp);
    int n = dice.size();
    
    vector<int> v;
    for (int i = 0; i < n / 2; i++) v.push_back(0);
    for (int i = n / 2; i < n; i++) v.push_back(1);
    
    do {
        vector<vector<int>> a;
        vector<vector<int>> b;
        vector<int> aOrder;
        for (int i = 0; i < n; i++) {
            if (v[i]) b.push_back(dice[i]);
            else {
                a.push_back(dice[i]);
                aOrder.push_back(i + 1);
            }
        }
        
        vector<int> asums;
        vector<int> bsums;
        for (int i = 0; i < pow(6, n / 2); i++) {
            int num = i;
            int asum = 0;
            int bsum = 0;
            for (int j = 0; j < n / 2; j++) {
                asum += a[j][num % 6];
                bsum += b[j][num % 6];
                num /= 6;
            }
            asums.push_back(asum);
            bsums.push_back(bsum);
        }
        
        sort(asums.begin(), asums.end());
        sort(bsums.begin(), bsums.end());
        
        int win = 0;
        int p1 = 0;
        int p2 = 0;
        while (p1 < asums.size() && p2 < bsums.size()) {
            if (asums[p1] > bsums[p2]) {
                win += (asums.size() - p1);
                p2++;
            } else {
                p1++;
            }
        }
        
        rank.push({ win, aOrder });
    } while (next_permutation(v.begin(), v.end()));

    return rank.top().second;
}