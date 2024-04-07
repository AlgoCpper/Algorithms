#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;
map<string, set<string>> myReport; // 유저 : 해당 유저를 신고한 ID
map<string, int> user;             // id : index

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    answer = vector<int>(id_list.size(), 0);

    int index = 0;
    for (string id : id_list)
    {
        user[id] = index++; // id : index
    }

    for (string str : report)
    {
        string userId = "", reportedId = "";
        bool flag = false;
        for (char c : str)
        {
            if (c == ' ')
            {
                flag = true;
                continue;
            }
            if (flag)
            {
                reportedId += c;
                continue;
            }
            userId += c;
        }
        myReport[reportedId].insert(userId);
    }

    for (string id : id_list)
    {
        if (myReport[id].size() >= k)
        {
            for (string reportMe : myReport[id])
            {
                int i = user[reportMe];
                answer[i]++;
            }
        }
    }

    return answer;
}