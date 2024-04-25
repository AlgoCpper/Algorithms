#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isSosu(long n)
{
    if (n == 1 || n == 0)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k)
{
    int answer = 0;
    string kNum = "";

    while (n >= k)
    {
        string i = to_string(n % k);
        n /= k;
        kNum += i;
    }
    kNum += to_string(n);
    reverse(kNum.begin(), kNum.end());

    vector<long> integer;
    string temp = "";

    for (int i = 0; i < kNum.size(); i++)
    {
        char num = kNum[i];
        if (i == kNum.size() - 1)
        {
            temp += num;
            integer.push_back(stol(temp));
            break;
        }
        if (num == '0')
        {
            if (temp == "")
                continue;
            integer.push_back(stol(temp));
            temp = "";
            continue; // core dump??
        }
        temp += num;
    }

    for (long i : integer)
    {
        if (isSosu(i))
            answer++;
    }

    return answer;
}