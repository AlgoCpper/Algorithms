#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int point, donut = 0, stick = 0, eight = 0;

struct Node
{
    vector<int> in;
    vector<int> out;
};

bool visit[1000001];
Node node[1000001];

void dfs(int start)
{
    visit[start] = true;
    int temp = start;

    while (true)
    {
        if (node[temp].out.size() == 0)
        {
            stick++;
            return;
        }
        else if (node[temp].out.size() == 2)
        {
            eight++;
            return;
        }
        int next_ = node[temp].out[0];
        if (visit[next_])
        {
            donut++;
            return;
        }
        temp = next_;
    }
}

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer;

    for (auto i : edges)
    {
        int s = i[0], e = i[1];
        node[s].out.push_back(e);
        node[e].in.push_back(s);
    }

    for (int i = 1; i <= edges.size(); i++)
    {
        if (node[i].in.size() == 0 && node[i].out.size() >= 2)
        {
            point = i;
        }
    }

    answer.push_back(point);

    for (int start : node[point].out)
    {
        dfs(start);
    }

    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);

    return answer;
}