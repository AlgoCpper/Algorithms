//G4_1715
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 우선순위 큐, 오름차순 정렬
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, input;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> input;
        pq.push(input);
    }

    int cnt=0;
    while(pq.size()>1){
        int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a+b);
        cnt+=(a+b);
    }
    cout << cnt;
    
}
