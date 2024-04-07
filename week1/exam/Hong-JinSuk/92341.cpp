#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// fees : 기본, 기본 요금, 단위, 단위 요금
vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, pair<int, bool>> info; // carNum, time, state
    map<string, int> myTime;           // carNum, useTime
    int basicTime = fees[0], basicFee = fees[1], unitTime = fees[2], unitFee = fees[3];
    for (string record : records)
    {
        int time = stoi(record.substr(0, 2)) * 60 + stoi(record.substr(3, 2));
        string carNum = record.substr(6, 4);
        string type = record.substr(11, 3);
        if (type == "IN")
            info[carNum] = {time, true};
        if (type == "OUT")
        {
            myTime[carNum] += time - info[carNum].first;
            info[carNum].second = false;
            // cout<<carNum<<" "<<myTime[carNum]<<endl;
        }
    }
    for (string record : records)
    {
        string carNum = record.substr(6, 4);
        if (info[carNum].second)
        {
            myTime[carNum] += 1439 - info[carNum].first;
            info[carNum].second = false;
            // cout<<carNum<<" "<<myTime[carNum]<<endl;
        }
    }

    for (auto timeInfo : myTime)
    {
        int fee = basicFee;
        if (timeInfo.second - basicTime > 0)
        {
            fee += ((timeInfo.second - basicTime) / unitTime) * unitFee;
            if ((timeInfo.second - basicTime) % unitTime > 0)
                fee += unitFee;
        }
        answer.push_back(fee);
    }
    return answer;
}