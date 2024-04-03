#include <bits/stdc++.h>
using namespace std;

int n;
int board[22][22];
int dist[22][22];
int prey[22][22];
queue<pair<int, int>> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
pair<int, int> shark;
int sharkSize = 2;
int ate = 0;
int t = 0;

void init() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    fill(&dist[0][0], &dist[21][22], -1);
    fill(&prey[0][0], &prey[21][22], 999999999);
}

void readBoard() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];

            if (board[i][j] == 9) {
                shark = { i, j };
                q.push( { i, j } );
                dist[i][j] = 0;
            }
        }
    }
}

bool floodfill() {
    bool hasPrey = false;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                if (dist[nx][ny] != -1) continue;
                if (board[nx][ny] > sharkSize) continue;
                dist[nx][ny] = dist[x][y] + 1;

                if (board[nx][ny] > 0 && board[nx][ny] < sharkSize) {
                    prey[nx][ny] = dist[nx][ny];
                    hasPrey = true;
                }
                q.push( { nx, ny } );
            }
        }
    return hasPrey;
}

pair<int, int> getNextPrey(int mn) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (prey[i][j] == mn) {
                return { i , j };
            }
        }
    }
    return { n, n } ;
}

void eat() {
    ate++;
    if (ate == sharkSize) {
        ate = 0;
        sharkSize++;
    }
}

void move(pair<int, int> next) {
    board[shark.first][shark.second] = 0;
    board[next.first][next.second] = 9;
    shark = next;
}

void initForNext(pair<int, int> next) {
    q.push(next);
    fill(&dist[0][0], &dist[n - 1][n], -1);
    fill(&prey[0][0], &prey[n - 1][n], 999999999);
    dist[next.first][next.second] = 0;
}

int main() {
    init();
    readBoard();

    while(1) {
        bool hasPrey = floodfill();
        if (!hasPrey) break;

        int mn = *min_element(&prey[0][0], &prey[n][n]);
        t += mn;

        pair<int, int> next = getNextPrey(mn);

        eat();
        move(next);

        initForNext(next);
    }

    cout << t;
}