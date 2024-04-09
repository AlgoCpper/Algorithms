#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> q;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        q.push(-num);
    }
}

long sol()
{
    long answer = 0;

    while (q.size() > 1)
    {
        int num1 = -q.top();
        q.pop();
        int num2 = -q.top();
        q.pop();
        int num3 = num1 + num2;
        answer += num3;
        q.push(-num3);
    }

    return answer;
}
int main()
{

    input();
    cout << sol();

    return 0;
}
