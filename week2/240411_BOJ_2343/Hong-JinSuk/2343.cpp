#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> lecture;
int answer = 1000000000; // N * 강의
void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int minute;
        cin >> minute;
        lecture.push_back(minute);
    }
}

bool canMake(int blueRay)
{
    int acc = 0;
    int cnt = M;
    for (int lectureTime : lecture)
    {
        if (lectureTime > blueRay)
            return false;
        if (lectureTime + acc <= blueRay)
        {
            acc += lectureTime;
        }
        else
        {
            cnt--;
            acc = lectureTime;
        }
        if (cnt == 0)
            return false;
    }
    return true;
}

void sol()
{
    int minTime = 0;
    int maxTime = 1000000000;
    int midTime;
    while (minTime < maxTime)
    {
        midTime = (minTime + maxTime) / 2;
        if (canMake(midTime))
        {
            maxTime = midTime;
        }
        else
        {
            minTime = midTime + 1;
        }
    }
    cout << maxTime;
}

int main()
{

    input();
    sol();
    return 0;
}