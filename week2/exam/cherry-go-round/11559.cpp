#include <bits/stdc++.h>
using namespace std;

string board[15];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visited[12][6];

bool bfs(int x, int y, char c, bool puyo) {
    bool copied[12][6];

    copy(&visited[0][0], &visited[11][6], &copied[0][0]);

    copied[x][y] = true;

    queue<pair<int, int>> q;

    q.push({ x, y });

    int cnt = 1;
    
    while(!q.empty()) {
        auto p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (copied[nx][ny]) continue;
            if (board[nx][ny] != c) continue;

            copied[nx][ny] = true;
            q.push({ nx, ny });
            cnt++;
        }
    }

    if (cnt >= 4) {
        copy(&copied[0][0], &copied[11][6], &visited[0][0]);
        return true;
    }
    return puyo;
}

void changeMap() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (visited[i][j]) board[i][j] = '.';
        }
    }

    stack<char> st;

    for (int j = 0; j < 6; j++) {
        for (int i = 11; i >= 0; i--) {
            if (board[i][j] == '.') continue;

            st.push(board[i][j]);
            board[i][j] = '.';
        }

        while(!st.empty()) {
            board[12 - st.size()][j] = st.top();
            st.pop();
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 12; i++) cin >> board[i];

    int cnt = 0;

    while(true) {
        bool puyo = false;

        fill(&visited[0][0], &visited[11][6], false);

        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (visited[i][j] || board[i][j] == '.') continue;
                puyo = bfs(i, j, board[i][j], puyo);
            }
        }

        if (!puyo) break;

        changeMap();
        cnt++;
    }

    cout << cnt;
}