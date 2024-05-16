package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BoJ_11054_가장_긴_바이토닉_부분_수열 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] input = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            input[i] = Integer.parseInt(st.nextToken());
        }

        int[] l_dp = new int[N];
        for (int i = 0; i < N; i++) {
            l_dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (input[i] > input[j]) {
                    l_dp[i] = Math.max(l_dp[j] + 1, l_dp[i]);
                }
            }
        }

        int[] r_dp = new int[N];
        for (int i = N-1; i >= 0; i--) {
            r_dp[i] = 1;
            for (int j = N-1; j >= i; j--) {
                if (input[i] > input[j]) {
                    r_dp[i] = Math.max(r_dp[j] + 1, r_dp[i]);
                }
            }
        }

        int max = 0;
        for (int i = 0; i < N; i++) {
            max = Math.max(max, l_dp[i] + r_dp[i]);
        }

        System.out.println(max - 1);
    }
}
