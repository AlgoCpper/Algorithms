package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.*;

public class BoJ_16197_두_동전 {

    private static class Coin {
        int x;
        int y;
        int c;

        public Coin(int x, int y, int c) {
            this.x = x;
            this.y = y;
            this.c = c;
        }
    }
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int N, M;
    static String[][] map;
    static Queue<List<Coin>> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new String[N][M];
        List<Coin> coins = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            String[] str = br.readLine().split("");
            for (int j = 0; j < M; j++) {
                map[i][j] = str[j];
                if (map[i][j].equals("o")) {
                    coins.add(new Coin(i, j, 0));
                }
            }
        }
        q.offer(coins);

        bfs();

    }

    private static void bfs() {

        while (!q.isEmpty()) {

            List<Coin> coins = q.poll();

            if (coins.size() == 1) {
                System.out.println(coins.get(0).c);
                return;
            }

            for (int d = 0; d < 4; d++) {

                List<Coin> newCoins = new ArrayList<>();

                for (Coin coin : coins) {

                    int nx = coin.x + dx[d];
                    int ny = coin.y + dy[d];
                    int nc = coin.c + 1;

                    if (nc > 10 || nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                    if (map[nx][ny].equals("#")) {
                        newCoins.add(new Coin(coin.x, coin.y, nc));
                    } else {
                        newCoins.add(new Coin(nx, ny, nc));
                    }
                }

                if (!newCoins.isEmpty()) {
                    q.offer(newCoins);
                }
            }
        }
        System.out.println("-1");
    }

}
