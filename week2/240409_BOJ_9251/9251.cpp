//G5_9251
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a;
    cin >> b;
    vector<vector<int>> LCS(a.size()+1, vector<int>(b.size()+1,0));
    for (int i=0; i<=a.size(); i++){
        for (int j=0; j<=b.size(); j++){
            if (i==0 || j==0) LCS[i][j] = 0;
            else if (a[i-1]==b[j-1]) LCS[i][j] = LCS[i-1][j-1]+1;
            else LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
        }
    }
    cout << LCS[a.size()][b.size()];
}