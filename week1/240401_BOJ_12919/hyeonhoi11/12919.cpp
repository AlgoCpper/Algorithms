#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void comp(string s, string t) {
	if (s == t) {
		cout << 1 << '\n';
		exit(0);
	}
	if (s.length() > t.length()) {
		return;
	}
	if (t[t.length() - 1] == 'A') {
		string temp = t;
		temp.erase(temp.size() - 1);
		comp(s, temp);
	}
	if (t[0] == 'B') {
		string temp = t;
		reverse(temp.begin(), temp.end());
		temp.erase(temp.size() - 1);
		comp(s, temp);
	}
}

int main() {
	string s, t;
	cin >> s >> t;

	comp(s, t);
	cout << 0 << '\n';
	return 0;
}