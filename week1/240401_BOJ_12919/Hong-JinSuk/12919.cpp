#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool isAnswer = false;

string remove(string temp_s) {
	temp_s.pop_back();
	return temp_s;
}

string re(string temp_s) {
	reverse(temp_s.begin(), temp_s.end());
	temp_s.pop_back();
	return temp_s;
}

void sol(string S, string T) {

	if (T.size() == S.size()) {
		if (T == S) isAnswer = true;
		return;
	}
	while (T.size() > S.size()) {
		if (T[T.size() - 1] == 'A') {
			T = remove(T);
			sol(S, T);
			T += 'A';
		}

		if (T[0] == 'B') {
			T = re(T);
			sol(S, T);
		}
		return;
	}
}

void input(string& S, string& T) {
	cin >> S >> T;
}

int main() {
	
	string S, T;
	input(S, T);
	sol(S, T);
	if (isAnswer) cout << 1;
	else cout << 0;

	return 0;
}