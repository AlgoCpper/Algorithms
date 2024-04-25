package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class BoJ_14728_벼락치기 {

    static Unit[] units;

    static class Unit {
        int k;
        int s;

        public Unit(int k, int s) {
            this.k = k;
            this.s = s;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); //단원 개수
        int T = Integer.parseInt(st.nextToken()); //총 시간

        units = new Unit[N+1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());

            int K = Integer.parseInt(st.nextToken()); //단원 별 예상 공부시간
            int S = Integer.parseInt(st.nextToken()); //단원 별 문제 배점
            units[i] = new Unit(K, S);
        }

        int[][] dp = new int[N+1][T+1];
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= T; j++) {
                if (units[i].k <= j) {
                   dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-units[i].k] + units[i].s);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        System.out.println(dp[N][T]);
    }
}
