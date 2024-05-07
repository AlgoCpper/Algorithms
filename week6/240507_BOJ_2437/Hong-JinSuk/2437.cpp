#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> weight;
long N;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long chu;
        cin >> chu;
        weight.push_back(chu);
    }
    sort(weight.begin(), weight.end());
}

void sol()
{
    long answer = 1;

    for (long i : weight)
    {

        if (answer < i)
            break;

        answer += i;
    }

    cout << answer;
}

int main()
{

    input();
    sol();

    return 0;
}