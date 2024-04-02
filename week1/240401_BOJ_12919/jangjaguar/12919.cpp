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
        // �Ǵ� ��Ȳ �ϳ��� ������ 0 -> �������� �� 0
        if (str == a) return 0;
        else return 1;
    }

    // A�� ����
    if (str.substr(str.size()-1,1)=="A"){
        string tmp = str.substr(0,str.size()-1);
        result *= AB(tmp);
    }

    // B�� ������
    if (str.substr(0,1)=="B"){
        reverse(str.begin(), str.end());
        string tmp = str.substr(0,str.size()-1);
        result *= AB(tmp);
    }
    return result;
}
