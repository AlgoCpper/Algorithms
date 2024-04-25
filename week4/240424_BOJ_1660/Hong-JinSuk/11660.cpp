#include <iostream>

using namespace std;

int N, M, sx, sy, ex, ey;
int myMap[1025][1025];
int acc[1025][1025];

void accMap(int x, int y)
{
    acc[y][x] = myMap[y][x] + acc[y - 1][x] + acc[y][x - 1] - acc[y - 1][x - 1];
}

void makeAccMap()
{
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            accMap(x, y);
        }
    }
}

void input()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> N >> M;
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            cin >> myMap[y][x];
        }
    }
    makeAccMap();
}

int main()
{

    input();
    for (int i = 0; i < M; i++)
    {
        cin >> sy >> sx >> ey >> ex;
        cout << acc[ey][ex] + acc[sy - 1][sx - 1] - acc[sy - 1][ex] - acc[ey][sx - 1] << "\n";
    }

    return 0;
}