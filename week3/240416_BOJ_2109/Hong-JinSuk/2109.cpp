#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>> q;

int n;
bool visit[10001];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cost, day;
        cin >> cost >> day;
        q.push({cost, day});
    }
}

int sol()
{
    int answer = 0;
    int pass = 0;
    while (!q.empty())
    {
        int cost = q.top().first, day = q.top().second;
        q.pop();
        if (day < pass)
            continue;
        for (int i = day; i > 0; i--)
        {
            if (!visit[i])
            {
                visit[i] = true;
                answer += cost;
                break;
            }
            if (i == 1)
                pass = day;
        }
    }
    return answer;
}

int main()
{
    input();
    cout << sol();
    return 0;
}