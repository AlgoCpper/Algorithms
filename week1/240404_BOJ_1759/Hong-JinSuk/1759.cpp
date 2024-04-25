#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int L, C;
bool visit[15];
vector<char> word;
set<string> answer;

void input()
{
    cin >> L >> C;
    word = vector<char>(C);
    for (int i = 0; i < C; i++)
    {
        cin >> word[i];
    }
    sort(word.begin(), word.end());
}

bool isPassword(string password)
{
    int passwordSize = password.size();
    bool aeiou = false;
    for (char c : password)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            passwordSize--;
            aeiou = true;
        }
    }
    if (passwordSize >= 2 && aeiou)
        return true;
    return false;
}

void dfs(int cnt, int index, string password)
{
    if (cnt == L)
    {
        if (isPassword(password))
            cout << password << endl;
        return;
    }

    for (int i = index; i < C; i++)
    {
        password += word[i];
        dfs(cnt + 1, i + 1, password);
        password.pop_back();
    }
    return;
}

int main()
{

    input();
    dfs(0, 0, "");
    return 0;
}