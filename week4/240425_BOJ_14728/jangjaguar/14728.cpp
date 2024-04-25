//G5_14728
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, t;
int channel, broken;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t;
    vector<int> chaos(10001,0);
    for (int i=0; i<n; i++) {
		int k, s;
		cin >> k >> s;
		for (int j = t; j >= k; j--) {
			chaos[j] = max(chaos[j-k]+s, chaos[j]);
		}
	}
	cout << chaos[t];
    
}