//G5_12919
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int AB(string str);

string a, b;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a;
    cin >> b;
    if (AB(b)==0) cout << 1;
    else cout << 0;
}

int AB(string str){
    int result = 1;
    if (str.size()==a.size()){
        // 되는 상황 하나라도 있으면 0 -> 곱해지면 다 0
        if (str == a) return 0;
        else return 1;
    }

    // A로 끝남
    if (str.substr(str.size()-1,1)=="A"){
        string tmp = str.substr(0,str.size()-1);
        result *= AB(tmp);
    }

    // B로 시작함
    if (str.substr(0,1)=="B"){
        reverse(str.begin(), str.end());
        string tmp = str.substr(0,str.size()-1);
        result *= AB(tmp);
    }
    return result;
}
