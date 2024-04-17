#include <iostream>
#include <vector>

using namespace std;

int N, maxCost;
int sum = 0;
int Max = 0;
vector<int> country;

void input()
{
    cin >> N;
    country = vector<int>(N);

    for (int i = 0; i < N; i++)
    {
        cin >> country[i];
        sum += country[i];
        Max = max(Max, country[i]);
    }
    cin >> maxCost;
}

bool isCan(int mid)
{
    int cost = 0;
    for (int cash : country)
    {
        if (cash <= mid)
            cost += cash;
        else
            cost += mid;
    }
    if (cost <= maxCost)
        return true;
    else
        return false;
}

/*
int sol() {
    int left = 0, right = maxCost;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isCan(mid)) left = mid + 1;
        else right = mid - 1;
    }
    return right;
}
*/

int sol()
{
    int left = 0, right = maxCost;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isCan(mid))
            left = mid + 1;
        else
            right = mid;
    }
    return left - 1;
}

int main()
{

    input();
    if (sum <= maxCost)
    {
        cout << Max;
        return 0;
    }
    cout << sol();

    return 0;
}