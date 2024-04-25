#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<pair<int, int>> Edge[20001]; // next cost
queue<int> q;
priority_queue<pair<int, int>> pq; // cost next
int V, E, K;
int Dist[20001];

void input()
{
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        Edge[start].push_back({end, cost});
    }
}

void sol()
{

    while (!pq.empty())
    {
        int cur = pq.top().second, curCost = -pq.top().first;
        pq.pop();
        for (auto near : Edge[cur])
        {
            int next = near.first;
            int cost = near.second;
            if (Dist[next] > Dist[cur] + cost)
            {
                pq.push({-(Dist[cur] + cost), next});
                Dist[next] = Dist[cur] + cost;
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (Dist[i] == INF)
        {
            cout << "INF\n";
            continue;
        }
        cout << Dist[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    for (int j = 1; j <= V; j++)
    {
        if (j == K)
            continue;
        Dist[j] = INF;
    }
    pq.push({0, K});
    sol();
    return 0;
}