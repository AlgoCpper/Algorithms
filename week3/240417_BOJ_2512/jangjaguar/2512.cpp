//S2_2512
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<int> jb(n,0);
    for (int i=0; i<n; i++){
        cin >> jb[i];
    }
    sort(jb.begin(), jb.end());
    cin >> m;

    // a보다 작은 수가 있을 수 있어서
    int a=1;
    int b=jb[jb.size()-1];
    int maxCnt = 0;
    while (a<=b){
        int mid = (a+b)/2;
        int cnt = 0;
        for (int i=0; i<n; i++){
            if (mid>=jb[i]) cnt+=jb[i]; 
            else cnt+=mid;
        }

        if (cnt>m){
            b = mid-1;
        }
        else{
            if (maxCnt<cnt) maxCnt = cnt;
            a = mid+1;
        }
        
    }
    // m을 넘는 가장 작은 수가 a=> a-1(혹은 b)이 답
    cout << a-1;

}