#include <iostream>
#include <vector>
#define INF 987654321
​using namespace std;
​int N, M;
int answer = INF;
vector<pair<int, int>> chikenShop;
vector<pair<int, int>> home;
vector<vector<int>> myMap;
​void input()
{
    cin >> N >> M;
    myMap = vector<vector<int>>(N, vector<int>(N, 0));
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> myMap[y][x];
            if (myMap[y][x] == 1)
            {
                home.push_back({y, x});
            }
            else if (myMap[y][x] == 2)
            {
                chikenShop.push_back({y, x});
            }
        }
    }
}
​int chikenDist(vector<pair<int, int>> myPick)
{
    int totalDist = 0;
    for (pair<int, int> myHome : home)
    {
        int dist = INF;
        for (pair<int, int> shop : myPick)
        {
            dist = min(dist, abs(shop.first - myHome.first) + abs(shop.second - myHome.second));
        }
        totalDist += dist;
    }
    return totalDist;
}

​void sol(int index, vector<pair<int, int>> myPick)
{
    if (myPick.size() == M)
    {
        answer = min(answer, chikenDist(myPick));
        return;
    }
    ​for (int i = index; i < chikenShop.size(); i++)
    {
        myPick.push_back(chikenShop[i]);
        sol(i + 1, myPick);
        myPick.pop_back();
    }
    ​return;
}

​int main()
{
    ​input();
    vector<pair<int, int>> myPick;
    sol(0, myPick);
    cout << answer;
    ​return 0;
}