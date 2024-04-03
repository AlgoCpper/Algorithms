#include <iostream>
#include <algorithm>

using namespace std;

string sol(string str) {
    string temp = "";
    int tempIndex = 0;
    for (int i = 0; i < str.size(); i++) {
        temp += str[i];
        // cout << temp << endl; 진행 과정을 볼 수 있다.
        if (temp.size() >= 4 && temp.substr(temp.size() - 4, 4) == "PPAP") { // PPAP 라면
            for (int j = 0; j < 3; j++) { // PPAP -> P
                temp.pop_back();
            }
        }
    }
    if (temp == "P") // PPAP 가 남았어도  PPAP -> P 가 되므로 이런 조건을 넣어줌.
        str = "PPAP";
    else {
        str = "NP";
    }
    return str;
}

void input(string &str) {
    cin >> str;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    input(str);
    cout << sol(str);

    return 0;
}