package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BoJ_18428_감시_피하기 {

    static int N;
    static String[][] map;
    static String answer = "NO";
    static ArrayList<Pos> t = new ArrayList<>();
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
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

        N = Integer.parseInt(br.readLine());

        map = new String[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = st.nextToken();
                if (map[i][j].equals("T")) t.add(new Pos(i, j));
            }
        }

        obstacle(0);
        System.out.print("NO");
    }

    public static void obstacle(int depth) {
        if(depth == 3) {
            if(bfs()) {
                System.out.print("YES");
                System.exit(0);
            }
            return;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j].equals("X")) {
                    map[i][j] = "O";
                    obstacle(depth + 1);
                    map[i][j] = "X";
                }
            }
        }
    }

    public static boolean bfs() {

        for (Pos p : t) {
            for (int d = 0; d < 4; d++) {
                int nx = p.x + dx[d];
                int ny = p.y + dy[d];

                while (nx >= 0 && ny >= 0 && nx < N  && ny < N) {

                    if (map[nx][ny].equals("S")) return false;
                    else if (map[nx][ny].equals("O")) break;

                    nx += dx[d];
                    ny += dy[d];
                }
            }
        }

        return true;
    }
}
