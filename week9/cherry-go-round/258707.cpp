#include <bits/stdc++.h>

using namespace std;

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    unordered_set<int> a;
    unordered_set<int> b;
    
    for (int i = 0; i < n / 3; i++) {
        a.insert(cards[i]);
    }
    
    int cnt;
    for (int i = n / 3, cnt = 1; i <= n - 2; i += 2, cnt++) {
        int card1 = cards[i];
        int card2 = cards[i + 1];
        b.insert(card1);
        b.insert(card2);
        
        bool aa = 0;
        for (int card : a) {
            if (a.find(n + 1 - card) != a.end()) {
                a.erase(card);
                a.erase(n + 1 - card);
                aa = 1;
                break;
            }
        }
        if (aa) continue;
        
        if (coin >= 1) {
            bool ab = 0;
            for (int card : a) {
                if (b.find(n + 1 - card) != b.end()) {
                    a.erase(card);
                    b.erase(n + 1 - card);
                    ab = 1;
                    coin--;
                    break;
                }
            }
            if (ab) continue;
        }
        
        if (coin >= 2) {
            bool bb = 0;
            for (int card : b) {
                if (b.find(n + 1 - card) != b.end()) {
                    b.erase(card);
                    b.erase(n + 1 - card);
                    bb = 1;
                    coin -= 2;
                    break;
                }
            }
            if (bb) continue;
        }
        
        return cnt;
    }

    return cnt;
}