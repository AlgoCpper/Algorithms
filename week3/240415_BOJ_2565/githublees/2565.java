package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BoJ_2565_전깃줄 {

    static int[][] wire;
    static int[] dp;

    static int max = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        wire = new int[N][2];
        dp = new int[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            wire[i][0] = Integer.parseInt(st.nextToken());
            wire[i][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(wire, (x, y) -> x[0] - y[0]);

        for (int i = 0; i < N; i++) {
            max = Math.max(max, cases(i));
        }

        System.out.println(N - max);
    }

    private static int cases(int N) {

        if(dp[N] == 0) {

            dp[N] = 1;

            for (int i = N+1; i < dp.length; i++) {

                if(wire[N][1] < wire[i][1])
                    dp[N] = Math.max(dp[N], cases(i) + 1);
            }
        }

        return dp[N];
    }
}
