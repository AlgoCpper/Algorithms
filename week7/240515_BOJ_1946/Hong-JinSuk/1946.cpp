#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> vec;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
}

void sol()
{
    int answer = 1;
    int minScore = vec[0].second;
    for (int i = 1; i < N; i++)
    {
        if (vec[i].second > minScore)
            continue;
        minScore = vec[i].second;
        answer++;
    }
    cout << answer << endl;
}

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        input();
        sol();
        vec.clear();
    }
}