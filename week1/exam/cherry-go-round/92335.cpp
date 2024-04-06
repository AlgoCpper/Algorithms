#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(long num) {
    if (num == 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

string solve(int n, int k) {
    if (k == 10) return to_string(n);
    string converted = "";
    
    while (n > 0) {
        converted += '0' + n % k;
        n /= k;
    }
    
    reverse(converted.begin(), converted.end());
    return converted;
}

int solution(int n, int k) {
    
    string converted = solve(n, k);
    int cnt = 0;
    string tmp = "";
    
    for (char c : converted) {
        
        if (c == '0') {
            if (tmp == "") continue;
            if (isPrime(stol(tmp))) cnt++;
            tmp = "";
            continue;
        }
        
        tmp = tmp + c;
    }
    
    if (tmp != "" && isPrime(stol(tmp))) cnt++;
    
    return cnt;
}