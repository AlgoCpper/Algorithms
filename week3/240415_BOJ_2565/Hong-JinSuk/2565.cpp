#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int *dp;
vector<pair<int, int>> building;

void input()
{
    cin >> N;
    dp = new int[N + 1];
    building.push_back({-1, -1});
    for (int i = 1; i <= N; i++)
    {
        int left, right;
        cin >> left >> right;
        building.push_back({left, right});
        dp[i] = 1;
    }
    sort(building.begin(), building.end());
}

void sol()
{
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (building[i].second > building[j].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(dp[i], answer);
    }
    cout << N - answer;
}

int main()
{

    input();
    sol();

    return 0;
}