#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, S;
bool complete = false;
vector<int> arr;

void input()
{
    cin >> N >> S;
    arr = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] >= S)
        {
            complete = true;
            break;
        }
    }
}

void sol()
{
    int left = 0, right = 0;
    int sum = 0;
    int len = N + 1;
    while (1)
    {

        if (sum < S)
        {
            if (right == N)
                break;
            sum += arr[right++];
        }
        else if (sum >= S)
        {
            len = min(len, right - left);
            sum -= arr[left++];
        }
    }
    if (len == N + 1)
    {
        cout << 0;
        return;
    }
    cout << len;
}

// DP?? 이분 탐색?? 투 포인터??
int main()
{

    input();
    if (complete)
    {
        cout << 1;
        return 0;
    }
    sol();

    return 0;
}