#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int n = board[0].size();
    int m = board.size();
    
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i < skill.size(); i++) {
        vector<int> row = skill[i];
        int type = row[0];
        int r1 = row[1];
        int c1 = row[2];
        int r2 = row[3];
        int c2 = row[4];
        int degree = row[5];
        
        int diff = type == 1 ? -degree : degree;
        
        sum[r1][c1] += diff;
        sum[r1][c2 + 1] -= diff;
        sum[r2 + 1][c1] -= diff;
        sum[r2 + 1][c2 + 1] += diff;
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            sum[i][j] += sum[i][j - 1];
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sum[i][j] + board[i][j] > 0) answer++;
        }
    }
    return answer;
}