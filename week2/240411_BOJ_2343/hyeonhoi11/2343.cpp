#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, M;
	vector<int> vec;
	cin >> N >> M;

	int start=0, end = 0;

	for(int i=0; i<N; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
		end += vec[i];
		start = max(x, start);
	}

	while (start <= end) {
		int mid = (start + end) / 2;
		int sum = 0, cnt = 0;

		for (int i = 0; i < N; i++) {
			if (sum + vec[i] > mid) {
				sum = 0; 
				cnt++;
			}
			sum += vec[i];
		}
		if (sum != 0) cnt++;

		if (cnt > M) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << start << '\n';
}