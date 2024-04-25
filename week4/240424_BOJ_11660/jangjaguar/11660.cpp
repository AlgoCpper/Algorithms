//S1_11660
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sumNum (n+1, vector<int>(n+1, 0));
    int input;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> input;
            sumNum[i][j] = sumNum[i][j-1]+sumNum[i-1][j]-sumNum[i-1][j-1]+input;
        }
    }

    // find
    int x1, y1, x2, y2;
    for (int i=0; i<m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sumNum[x2][y2] - sumNum[x1-1][y2] - sumNum[x2][y1-1] + sumNum[x1-1][y1-1] << "\n";
    }
}