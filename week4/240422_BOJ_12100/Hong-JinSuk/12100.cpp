#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N;
int myMap[21][21];
int answer = 0;
queue<int> q;

void input()
{
    cin >> N;
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            cin >> myMap[y][x];
        }
    }
}

void up()
{
    for (int x = 1; x <= N; x++)
    {
        for (int y = 1; y <= N; y++)
        {
            if (myMap[y][x] == 0)
                continue;
            q.push(myMap[y][x]);
            myMap[y][x] = 0;
        }
        int index = 1;
        while (!q.empty())
        {
            int num = q.front();
            q.pop();
            if (myMap[index][x] == 0)
                myMap[index][x] = num;
            else
            {
                if (myMap[index][x] == num)
                    myMap[index++][x] *= 2;
                else
                {
                    myMap[++index][x] = num;
                }
            }
        }
    }
}

void down()
{
    for (int x = 1; x <= N; x++)
    {
        for (int y = N; y >= 1; y--)
        {
            if (myMap[y][x] == 0)
                continue;
            q.push(myMap[y][x]);
            myMap[y][x] = 0;
        }
        int index = N;
        while (!q.empty())
        {
            int num = q.front();
            q.pop();
            if (myMap[index][x] == 0)
                myMap[index][x] = num;
            else
            {
                if (myMap[index][x] == num)
                    myMap[index--][x] *= 2;
                else
                {
                    myMap[--index][x] = num;
                }
            }
        }
    }
}

void left()
{
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            if (myMap[y][x] == 0)
                continue;
            q.push(myMap[y][x]);
            myMap[y][x] = 0;
        }
        int index = 1;
        while (!q.empty())
        {
            int num = q.front();
            q.pop();
            if (myMap[y][index] == 0)
                myMap[y][index] = num;
            else
            {
                if (myMap[y][index] == num)
                    myMap[y][index++] *= 2;
                else
                {
                    myMap[y][++index] = num;
                }
            }
        }
    }
}

void right()
{
    for (int y = 1; y <= N; y++)
    {
        for (int x = N; x >= 1; x--)
        {
            if (myMap[y][x] == 0)
                continue;
            q.push(myMap[y][x]);
            myMap[y][x] = 0;
        }
        int index = N;
        while (!q.empty())
        {
            int num = q.front();
            q.pop();
            if (myMap[y][index] == 0)
                myMap[y][index] = num;
            else
            {
                if (myMap[y][index] == num)
                    myMap[y][index--] *= 2;
                else
                {
                    myMap[y][--index] = num;
                }
            }
        }
    }
}

void move(int dir)
{

    switch (dir)
    {
    case 1:
        right();
        break;
    case 2:
        left();
        break;
    case 3:
        down();
        break;
    case 4:
        up();
        break;
    default:
        break;
    }
}

void dfs(int cnt)
{
    if (cnt == 0)
        return;

    int tempMap[21][21];
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            tempMap[y][x] = myMap[y][x];
        }
    }

    for (int dir = 1; dir <= 4; dir++)
    {
        move(dir);
        for (int y = 1; y <= N; y++)
        {
            for (int x = 1; x <= N; x++)
            {
                answer = max(answer, myMap[y][x]);
            }
        }
        dfs(cnt - 1);
        for (int y = 1; y <= N; y++)
        {
            for (int x = 1; x <= N; x++)
            {
                myMap[y][x] = tempMap[y][x];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    dfs(5);

    cout << answer;

    return 0;
}