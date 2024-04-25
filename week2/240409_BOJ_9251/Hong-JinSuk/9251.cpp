#include <iostream>
#include <string>

using namespace std;

string str1, str2;
// string answer = "";
int myMap[1001][1001];

void input()
{
    cin >> str1 >> str2;
}

int sol()
{
    for (int y = 1; y <= str1.size(); y++)
    {
        for (int x = 1; x <= str2.size(); x++)
        {
            if (str2[x - 1] == str1[y - 1])
            {
                myMap[y][x] = myMap[y - 1][x - 1] + 1;
            }
            else
            {
                myMap[y][x] = max(myMap[y - 1][x], myMap[y][x - 1]);
            }
        }
    }

    int sx = str2.size();
    int sy = str1.size();
    int answer = 0;

    while (sx != 0 && sy != 0)
    {
        if (myMap[sy - 1][sx] == myMap[sy][sx])
        {
            sy--;
        }
        else if (myMap[sy][sx - 1] == myMap[sy][sx])
        {
            sx--;
        }
        else
        {
            answer++;
            sy--;
            sx--;
        }
    }
    return answer;
}

int main()
{

    input();
    cout << sol() << endl;

    // for (int y = 1; y <= str1.size(); y++) {
    //	for (int x = 1; x <= str2.size(); x++) {
    //		cout << myMap[y][x] << " ";
    //	}
    //	cout << endl;
    // }

    return 0;
}