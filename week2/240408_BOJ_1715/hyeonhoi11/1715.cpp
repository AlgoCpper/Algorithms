#include<iostream>
#include<queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	while (N--) {
		int x;
		cin >> x;
		pq.push(x);
	}
	
	int answer = 0;

	while (pq.size() != 1) {
		int n1, n2;
		n1 = pq.top();
		pq.pop();
		n2 = pq.top();
		pq.pop();
		answer += n1 + n2;
		pq.push(n1 + n2);
	}
	cout << answer << '\n';
	return 0;
}