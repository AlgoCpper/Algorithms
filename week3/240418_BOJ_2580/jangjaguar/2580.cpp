//G4_2580
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sdoku(9, vector<int>(9,0));
vector<pair<int,int>> notNum;

void sdokuFill(int k);
bool tCheck(int notX, int notY, int t);

bool isNotfound = true;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cin >> sdoku[i][j];
            if (sdoku[i][j]==0) notNum.push_back(make_pair(i,j)); 
        }
    }
    sdokuFill(notNum.size()-1);
}

void sdokuFill(int k){
    if(!isNotfound) return;
    if (k==-1){
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                cout << sdoku[i][j] << " ";
            }
            cout << "\n";
        }
        isNotfound = false;

    }
    else{
        int notX = notNum[k].first;
        int notY = notNum[k].second;

        for(int t=1; t<=9; t++){
            if (tCheck(notX, notY, t)) {
                sdoku[notX][notY] = t;
                sdokuFill(k-1);
                sdoku[notX][notY] = 0;
            }
        }
    }
    
}

bool tCheck(int notX, int notY, int t){
    if (sdoku[notX-(notX%3)+0][notY-(notY%3)+0]==t || sdoku[notX-(notX%3)+0][notY-(notY%3)+1]==t || sdoku[notX-(notX%3)+0][notY-(notY%3)+2]==t
    || sdoku[notX-(notX%3)+1][notY-(notY%3)+0]==t || sdoku[notX-(notX%3)+1][notY-(notY%3)+1]==t || sdoku[notX-(notX%3)+1][notY-(notY%3)+2]==t
    || sdoku[notX-(notX%3)+2][notY-(notY%3)+0]==t || sdoku[notX-(notX%3)+2][notY-(notY%3)+1]==t || sdoku[notX-(notX%3)+2][notY-(notY%3)+2]==t) 
    return false;
    for (int i=0; i<9; i++){
        if (sdoku[notX][i]==t || sdoku[i][notY]==t) return false;   
    }
    return true;
}
