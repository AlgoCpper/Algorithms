//S4_2003
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> numbers(n+1, 0);
    for (int i=1; i<=n; i++){
        cin >> numbers[i];
        numbers[i] += numbers[i-1];
    }
    int a=0, b=1, cnt=0;
    while(b<=n){
        if (numbers[b]-numbers[a]==m){
            cnt++;
            b++;
        }
        else if(numbers[b]-numbers[a]>m){
            a++;
        }
        else{
            b++;
        }
    }
    
    cout << cnt;
}