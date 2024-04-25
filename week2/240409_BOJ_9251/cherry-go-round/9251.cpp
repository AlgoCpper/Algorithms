#include <bits/stdc++.h>
using namespace std;

string a, b;
int alen, blen;
int d[1005][1005];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> a >> b;
	alen = a.length();
	blen = b.length();

	for (int i = 0; i <= alen; i++) {
		for (int j = 0; j <= blen; j++) {
			if (i == 0 || j == 0) {
				d[i][j] = 0;
				continue;
			}

			if (a[i - 1] != b[j - 1]) {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
				continue;
			}

			d[i][j] = d[i - 1][j - 1] + 1;
		}
	}
	cout << d[alen][blen];
}