#include <iostream>
#include <deque>

using namespace std;

int myMap[9][9];
int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool isComplete = false;
deque<pair<int, int>> toFill;

bool canFill(int X, int Y, int num)
{

    // 3*3 격자 안에 같은 수가 있으면 못넣음
    int cy = (Y / 3) * 3, cx = (X / 3) * 3;
    for (int y = cy; y < cy + 3; y++)
    {
        for (int x = cx; x < cx + 3; x++)
        {
            if (myMap[y][x] == num)
                return false;
        }
    }

    for (int x = 0; x < 9; x++)
    {
        if (myMap[Y][x] == num)
            return false;
    }

    for (int y = 0; y < 9; y++)
    {
        if (myMap[y][X] == num)
            return false;
    }

    return true;
}

void dfs()
{
    if (isComplete)
        return;

    while (!toFill.empty())
    {
        int cy = toFill.front().first, cx = toFill.front().second;
        toFill.pop_front();
        for (int i = 0; i < 9; i++)
        {
            if (canFill(cx, cy, num[i]))
            {
                myMap[cy][cx] = num[i];
                dfs();
                if (isComplete)
                    return;
                myMap[cy][cx] = 0;
            }
            if (i == 8)
            {
                toFill.push_front({cy, cx});
                myMap[cy][cx] = 0;
                return;
            }
        }
    }
    isComplete = true;
    return;
}

void input()
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            cin >> myMap[y][x];
            if (myMap[y][x] == 0)
                toFill.push_back({y, x});
        }
    }
}

int main()
{

    input();
    dfs();
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            cout << myMap[y][x] << " ";
        }
        cout << endl;
    }
    return 0;
}