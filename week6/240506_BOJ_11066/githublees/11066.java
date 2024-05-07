package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BoJ_11066_파일_합치기 {

    static int T, K;
    static int[] sum; //파일 비용 합 저장 배열
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {

            K = Integer.parseInt(br.readLine());
            sum = new int[K+1];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= K; j++) {
                sum[j] = sum[j-1] + Integer.parseInt(st.nextToken());
            }

            fileMerge();
        }
    }

    private static void fileMerge() {
        dp = new int[K+1][K+1];
        // 1 ~ n까지 묶기 n <= K (몇장을 묶을지)
        for (int n = 1; n <= K; n++) {
            // 1 ~ K까지 from + n <= K (어디서부터 묶기 시작할건지)
            for (int from = 1; from + n <= K; from++) {
                int to = from + n;
                dp[from][to] = Integer.MAX_VALUE;
                // 1 ~ K까지 divide < from + n (범위가 주어졌을 때 특정 지점으로 나눠서 최대값 구하기)
                for (int divide = from; divide < to; divide++) {
                    dp[from][to] = Math.min(dp[from][to], dp[from][divide] + dp[divide + 1][to] + sum[to] - sum[from - 1]);
                }
            }
        }
        System.out.println(dp[1][K]);
    }
}
