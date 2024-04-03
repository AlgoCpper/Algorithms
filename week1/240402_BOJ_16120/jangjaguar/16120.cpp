//G4_16120
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string inputTxt;
    cin >> inputTxt;

    vector<string> Stack;
    for (int i=0; i<inputTxt.size(); i++){
        Stack.push_back(inputTxt.substr(i,1));

        while(Stack.size()>=4 && (Stack[Stack.size()-4]=="P") && (Stack[Stack.size()-3]=="P") && (Stack[Stack.size()-2]=="A") && (Stack[Stack.size()-1]=="P")){
            Stack.pop_back();
            Stack.pop_back();
            Stack.pop_back();
        }
    }
    
    if (Stack.size()==1 && Stack[0]=="P") cout << "PPAP";
    else cout << "NP";
}