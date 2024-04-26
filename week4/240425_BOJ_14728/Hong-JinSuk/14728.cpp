#include <iostream>
#include <vector>

using namespace std;

int N, T;
int dp[10001];
vector<pair<int, int>> lec; // 시간, 배점

void input()
{
    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        int K, S;
        cin >> K >> S;
        lec.push_back({K, S});
    }
}

void sol()
{
    for (int j = 0; j < N; j++)
    {
        int time = lec[j].first, score = lec[j].second;
        for (int i = T; i >= 0; i--)
        {
            if (time <= i)
            {
                dp[i] = max(dp[i], dp[i - time] + score);
            }
        }
    }
    cout << dp[T];
}

int main()
{

    input();
    sol();

    return 0;
}