#include <iostream>

using namespace std;

int paper[11][11];
int paperNum[6] = {0, 5, 5, 5, 5, 5};
int markNum = 0; // 칠해야할 종이 갯수
int answer = 9999;
void input()
{

    for (int y = 1; y <= 10; y++)
    {
        for (int x = 1; x <= 10; x++)
        {
            cin >> paper[y][x];
            if (paper[y][x] == 1)
                markNum++;
        }
    }
}

void attach(int x, int y, int Size, int result)
{
    for (int i = y; i < y + Size; i++)
    {
        for (int j = x; j < x + Size; j++)
        {
            paper[i][j] = result;
        }
    }
}

bool canAttach(int x, int y, int Size)
{
    for (int i = y; i < y + Size; i++)
    {
        for (int j = x; j < x + Size; j++)
        {
            if (paper[i][j] == 0)
                return false;
        }
    }
    return true;
}

void sol(int cnt)
{

    if (answer <= cnt)
        return; // 현재의 최소보다 같거나 많으면 의미 없음

    if (markNum == 0)
    {
        answer = cnt;
        return;
    }

    for (int y = 1; y <= 10; y++)
    {
        for (int x = 1; x <= 10; x++)
        {
            if (paper[y][x] == 1)
            {
                for (int Size = 5; Size >= 1; Size--)
                { // 색종이 크기는 큰 것 부터 넣어보자
                    if (canAttach(x, y, Size))
                    {
                        if (paperNum[Size] == 0)
                            continue;          // 색종이가 다 떨어졌으면 넘김
                        attach(x, y, Size, 0); // 색종이를 붙힘
                        markNum -= Size * Size;
                        paperNum[Size]--;

                        sol(cnt + 1);

                        attach(x, y, Size, 1); // 색종이를 다시 뗌
                        markNum += Size * Size;
                        paperNum[Size]++;
                    }
                }
                return; // 색종이를 붙이고, 다시 재귀를 돌기 때문에, 이 이상 진행할 필요없음.
            }
        }
    }
}

int main()
{

    input();
    sol(0);
    if (answer == 9999)
        cout << -1;
    else
        cout << answer;

    return 0;
}