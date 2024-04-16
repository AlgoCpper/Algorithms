//G5_2565
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> jbd(n,vector<int>(2,0));
    vector<int> dp(101,1);
    for (int i=0; i<n; i++){
        cin >>  jbd[i][0] >> jbd[i][1];
    }

    sort(jbd.begin(), jbd.end()); 

    // LCS
    for (int i=0; i<n; i++){
        int k=0;
        for (int j=0; j<i; j++){
            if (jbd[i][1]>jbd[j][1]) k = max(k, dp[j]);
        }
        dp[i] = k+1;
    }

    int maxK = 0;
    for (int i=0; i<n; i++) {
        if (maxK < dp[i]) maxK = dp[i];
    }
    cout << n-maxK;

    

}
