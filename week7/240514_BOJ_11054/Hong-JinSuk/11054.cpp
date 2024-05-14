#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;

int leftDp[1000];
int rightDp[1000];

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
        leftDp[i] = 1;
        rightDp[i] = 1;
    }
}

void sol()
{
    int answer = 0;

    for (int i = 1; i < N; i++)
    { // 현재 숫자
        for (int j = i - 1; j >= 0; j--)
        { // 비교군
            int postNum = arr[j];
            int curNum = arr[i];
            if (curNum > postNum)
            {
                if (rightDp[i] < rightDp[j] + 1)
                {
                    rightDp[i] = rightDp[j] + 1;
                }
            }
        }
    }

    for (int i = N - 2; i >= 0; i--)
    { // 현재 숫자
        for (int j = i + 1; j < N; j++)
        { // 비교군
            int postNum = arr[j];
            int curNum = arr[i];
            if (curNum > postNum)
            {
                if (leftDp[i] < leftDp[j] + 1)
                {
                    leftDp[i] = leftDp[j] + 1;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        answer = max(answer, rightDp[i] + leftDp[i]);
    }
    cout << answer - 1;
}

int main()
{

    input();
    sol();

    return 0;
}