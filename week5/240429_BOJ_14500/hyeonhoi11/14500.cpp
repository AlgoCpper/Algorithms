#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void getMaxNum(int x, int y, int cnt, int curScore);
int map[501][501], visit[501][501];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int N, M, ans=0;
int main(){
    memset(visit, 0, sizeof(visit));
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            visit[i][j] = 1;
            getMaxNum(i, j, 1, map[i][j]);
            visit[i][j] = 0;
        }
    }
    cout << ans;
}

void getMaxNum(int x, int y, int cnt, int curScore){
    if(cnt == 4) { 
        if(ans < curScore) ans = curScore;
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > M || visit[nx][ny]) continue;
        visit[nx][ny] = 1;
        getMaxNum(nx, ny, cnt+1, curScore+map[nx][ny]);
        visit[nx][ny] = 0; 
    }

    if(x-1 >= 1 && y-1 >= 1 && x+1 <= N) {
        ans = max(ans, (map[x-1][y] + map[x][y-1] + map[x][y] + map[x+1][y]));
    }
    if(x-1 >= 1 && y+1 <= M && x+1 <= N) {
        ans = max(ans, (map[x-1][y] + map[x][y+1] + map[x][y] + map[x+1][y]));
    }
    if(y-1 >= 1 && y+1 <= M && x+1 <= N) {
        ans = max(ans, (map[x][y] + map[x+1][y] + map[x+1][y-1] + map[x+1][y+1]));
    }
    if(y-1 >= 1 && y+1 <= M && x+1 <= N) {
        ans = max(ans, (map[x][y-1] + map[x][y] + map[x][y+1] + map[x+1][y]));
    }

}