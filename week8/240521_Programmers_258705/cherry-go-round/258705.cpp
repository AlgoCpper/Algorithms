#include<bits/stdc++.h>

using namespace std;

int d[100005][2];

int solution(int n, vector<int> tops) {
    
    d[n - 1][1] = tops[n - 1] + 3;
    d[n - 1][0] = tops[n - 1] + 2;
    
    for (int i = n - 2; i >= 0; i--) {
        d[i][1] = (((tops[i] + 2) * d[i + 1][1]) % 10007 + d[i + 1][0]) % 10007;
        d[i][0] = (((tops[i] + 1) * d[i + 1][1]) % 10007 + d[i + 1][0]) % 10007;
    }
    
    return d[0][1] % 10007;
}