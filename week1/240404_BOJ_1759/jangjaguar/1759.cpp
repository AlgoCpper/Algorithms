//G5_1759
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<char> code;
vector<char> codeList;

void DFS(int k);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> n >> m;
    codeList.resize(m, ' ');
    for (int i=0; i<m; i++){
        cin >> codeList[i];
    }
    sort(codeList.begin(), codeList.end());

    DFS(0);
}

void DFS(int k){
    if (code.size()==n){
        // 모음체크
        int aeiouCnt=0;
        for (int i=0; i<n; i++) {
            if (code[i]=='a' || code[i]=='e' || code[i]=='i' || code[i]=='o' || code[i]=='u') aeiouCnt++;
        }
        if (aeiouCnt>=1 && n-aeiouCnt >=2){
            for (int i=0; i<n; i++) cout << code[i];
            cout << "\n";
        }
        return;
    }

    // 백트래킹
    for (int i=k; i<m; i++){
        code.push_back(codeList[i]);
        DFS(i+1);
        code.pop_back();
    }
}