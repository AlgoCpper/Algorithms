//G4_14500
#include <iostream>
#include <vector>

using namespace std;

static vector<vector<bool>> visited;
static vector<vector<int>> tetro;

int n, m;
int maxT=0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//ㅗ튀어나온 부분 기준
int ex[4][4] = {{0, 1, 1, 1}, {0,-1, 0, 1}, {0,-1,-1,-1}, {0,-1, 0, 1}};
int ey[4][4] = {{0,-1, 0, 1}, {0, 1, 1, 1}, {0,-1, 0, 1}, {0,-1,-1,-1}};

void DFS(int x, int y, int four, int sumN);
void Tshape(int x, int y);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    visited.resize(n, vector<bool>(m,false));
    tetro.resize(n, vector<int>(m,0));
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> tetro[i][j];
        }
    }


    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            DFS(i, j, 1, 0);
            Tshape(i, j);
        }
    }
    cout << maxT;
}

void DFS(int x, int y, int four, int sumN){
    if (visited[x][y]) return;

    //visited[x][y] = true;
    sumN+=tetro[x][y];

    // 길이(4)로 재귀를 중단시켜서 무한루프 아님
    if (four == 4){
        if(sumN>maxT) {maxT = sumN;}
        return;
    }

    for (int k=0; k<4; k++){
        int newX = x+dx[k];
        int newY = y+dy[k];
        if((0<=newX && newX<n) && (0<=newY && newY<m) && !visited[newX][newY]){
            visited[x][y] = true;
            DFS(newX, newY, four+1, sumN);
            visited[x][y] = false;
        }
    }
    
    
}
void Tshape(int x, int y){
    for (int k=0; k<4; k++){
        int sumT=tetro[x][y];
        for (int f=1; f<=3; f++){
            int newX = x+ex[k][f];
            int newY = y+ey[k][f];
            if((0<=newX && newX<n) && (0<=newY && newY<m)){
                sumT+=tetro[newX][newY];
            }
            else break;
        }
        if(sumT>maxT) maxT = sumT;
    }
}