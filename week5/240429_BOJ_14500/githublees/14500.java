package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BoJ_14500_테트로미노 {


    static int answer = 0;
    static int N, M;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        visited = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                dfs(i, j, map[i][j], 1);
                T(i, j);
            }
        }

        System.out.println(answer);
    }

    private static void dfs(int x, int y, int sum, int count) {
        visited[x][y] = true;

        if (count == 4) {
            answer = Math.max(answer, sum);
            visited[x][y] = false;
            return;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]) continue;

            dfs(nx, ny, sum + map[nx][ny], count+1);
        }

        visited[x][y] = false;
    }

    private static void T(int x, int y) {
        for (int i = 0; i < 4; i++) {
            int sum = map[x][y];
            for (int d = 0; d < 4; d++) {

                if (d == i) continue;

                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;

                sum += map[nx][ny];
            }

            answer = Math.max(answer, sum);
        }
    }
}
