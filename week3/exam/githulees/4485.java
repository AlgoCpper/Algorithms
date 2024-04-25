package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BoJ_4485_젤다의_전설 {

    static int[][] map;
    static int[][] d;
    static int[] dx = {-1,1,0,0};
    static int[] dy = {0,0,-1,1};
    static class Pos implements Comparable<Pos>{
        int x;
        int y;
        int r;

        public Pos(int x, int y, int r) {
            this.x = x;
            this.y = y;
            this.r = r;
        }

        @Override
        public int compareTo(Pos o) {
            return Integer.compare(this.r, o.r);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int t = 1; ; t++) {

            int N = Integer.parseInt(br.readLine());

            if(N == 0) break;

            map = new int[N][N];
            d = new int[N][N];

            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
                Arrays.fill(d[i], Integer.MAX_VALUE);
            }

            dijkstra(N);

            System.out.println("Problem " + t + ": " + d[N-1][N-1]);
        }
    }

    private static void dijkstra(int n) {

        PriorityQueue<Pos> pq = new PriorityQueue<>();

        pq.offer(new Pos(0, 0, map[0][0]));

        while(!pq.isEmpty()) {

            Pos p = pq.poll();

            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n  || ny >= n) continue;

                int cost = p.r + map[nx][ny];

                if(d[nx][ny] > cost) {
                    d[nx][ny] = cost;
                    pq.offer(new Pos(nx, ny, cost));
                }
            }
        }
    }
}
