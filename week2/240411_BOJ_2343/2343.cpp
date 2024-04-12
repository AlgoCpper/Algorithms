//S1_2343
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> blue;

int main(){
    cin >> n >> m;
    blue.resize(n,0);
    int st = 0;
    int en = 0;

    for (int i=0; i<n; i++){ 
        cin >> blue[i];
        if (st<blue[i]) st = blue[i];
        en+=blue[i];
    }

    while (st<=en){
        int mid = (st+en)/2;
        int sum=0;
        int result=0;
        
        for(int i=0; i<n; i++){
            if (sum+blue[i] > mid){
                result++;
                sum=0;
            }
            sum+=blue[i];
        }
        if (sum!=0) result++;
        if (result > m) st = mid+1;
        else en = mid-1;
    }
    cout << st;
}