package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BoJ_2638_치즈 {

    static int N, M, count = 0, time = 0;
    static int[][] cheese;
    static boolean[][] visited;
    static ArrayList<Pos> cheeseList;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static class Pos {
        int x;
        int y;

        public Pos (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        cheese = new int[N][M];
        cheeseList = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                cheese[i][j] = Integer.parseInt(st.nextToken());
                if (cheese[i][j] == 1) {
                    cheeseList.add(new Pos(i, j));
                    count++;
                }
            }
        }

        while (count != 0) {
            time++;
            visited = new boolean[N][M];
            dfs(0, 0);
            melting();
        }

        System.out.println(time);
    }

    private static void melting() {
        for (int i = 0; i < cheeseList.size(); i++) {
            int x = cheeseList.get(i).x;
            int y = cheeseList.get(i).y;
            int cnt = 0;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (cheese[nx][ny] == 2) {
                    cnt++;
                }
            }

            if (cnt >= 2) {
                cheese[x][y] = 0;
                count--;
                cheeseList.remove(i);
                i--;
            }
        }
    }

    private static void dfs(int x, int y) {
        visited[x][y] = true;
        cheese[x][y] = 2;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M
                    || visited[nx][ny] || cheese[nx][ny] == 1) continue;

            dfs(nx, ny);
        }
    }
}
