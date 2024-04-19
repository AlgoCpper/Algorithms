package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BoJ_2580_스도쿠 {

    static int[][] sudoku;
    static ArrayList<Pos> empty_pos = new ArrayList<>();
    static class Pos {
        int x;
        int y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        sudoku = new int[9][9];
        for (int i = 0; i < 9; i++) {

            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int j = 0; j < 9; j++) {
                sudoku[i][j] = Integer.parseInt(st.nextToken());
                if (sudoku[i][j] == 0) empty_pos.add(new Pos(i, j));
            }
        }

        if(dfs(0)) {
            print();
        }
    }

    private static boolean dfs(int count) {
        //종료 조건
        if(count == empty_pos.size()) {
            return true;
        }

        Pos p = empty_pos.get(count);

        for (int i = 1; i <= 9; i++) {
            //만약 값이 들어갈 수 있다면
            if (checkSudoku(p.x, p.y, i) ) {
                sudoku[p.x][p.y] = i;
                //그 다음 빈칸의 값을 찾으러 재귀함수를 탄다.
                if (dfs(count+1)) { return true; }
                // 값이 들어갈 수 없다면 지금 위치의 값을 0으로 초기화
                else { sudoku[p.x][p.y] = 0; }
            }
        }

        return false;
    }

    private static boolean checkSudoku(int x, int y, int n) {
        //가로, 세로
        for (int i = 0; i < 9; i++) {
            if (sudoku[i][y] == n) return false;
            if (sudoku[x][i] == n) return false;
        }

        //3*3
        for (int i = x/3*3; i < x/3*3+3; i++) {
            for (int j = y/3*3; j < y/3*3+3; j++) {
                if (sudoku[i][j] == n) return false;
            }
        }
        return true;
    }

    private static void print() {

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {
                sb.append(sudoku[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }

}