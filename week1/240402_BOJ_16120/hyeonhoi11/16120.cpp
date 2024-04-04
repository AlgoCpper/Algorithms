#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	
	int cnt = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'P') {
			cnt++;
			continue;
		}

		if (cnt >= 2 && s[i+1] == 'P') {
			cnt--;
			i++;
		}
		else {
			cout << "NP" << '\n';
			return 0;
		}
	}

	if (cnt == 1) {
		cout << "PPAP" << '\n';
	}
	else {
		cout << "NP" << '\n';
	}

	return 0;
}