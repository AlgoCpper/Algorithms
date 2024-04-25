#include <bits/stdc++.h>
using namespace std;

int a[2020];
int n;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    int zerocnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) zerocnt++;
    }

    unordered_set<int> added;
    unordered_set<int> numbers;
    unordered_set<int> duplicated;

    for (int i = 0; i < n; i++) {
        if (numbers.find(a[i]) != numbers.end()) duplicated.insert(a[i]);
        numbers.insert(a[i]);

        for (int j = 0; j < i; j++) {
            if (a[i] != 0 && a[j] != 0) added.insert(a[i] + a[j]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (added.find(a[i]) != added.end()) cnt++;
        else if (a[i] != 0 && zerocnt > 0 && duplicated.find(a[i]) != duplicated.end()) cnt++;
        else if (a[i] == 0 && zerocnt >= 3) cnt++;
    }

    cout << cnt;
}