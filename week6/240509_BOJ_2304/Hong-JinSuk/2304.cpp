#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
pair<int, int> largestPillar = {0, 0};
vector<pair<int, int>> pillar;

void input()
{

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y > largestPillar.second)
        {
            largestPillar.first = x;
            largestPillar.second = y;
        }
        pillar.push_back({x, y});
    }

    sort(pillar.begin(), pillar.end());
}

void sol()
{

    int answer = 0;
    int post_x = 0, next_x = 0, y = 0;

    for (int i = 0; i < N; i++)
    {

        auto cur = pillar[i];

        if (i == 0)
        {
            post_x = cur.first;
            y = cur.second;
            continue;
        }

        if (cur.second >= y)
        {
            answer += (cur.first - post_x) * y;
            post_x = cur.first;
            y = cur.second;
        }

        if (cur.first == largestPillar.first)
        {
            break;
        }
    }

    for (int i = N - 1; i > 0; i--)
    {

        auto cur = pillar[i];

        if (i == N - 1)
        {
            post_x = cur.first;
            y = cur.second;
            continue;
        }

        if (cur.second >= y)
        {
            answer += (post_x - cur.first) * y;
            post_x = cur.first;
            y = cur.second;
        }

        if (cur.first == largestPillar.first)
            break;
    }

    answer += largestPillar.second;

    cout << answer << endl;
}

int main()
{

    input();
    sol();

    return 0;
}