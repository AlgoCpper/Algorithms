package programmers;

public class Pro_258705_산_모양_타일링_자바 {
    private static final int MOD = 10007;

    public int solution(int n, int[] tops) {
        int answer = 0;

        int[][] dp = new int[n][2];

        dp[0][0] = tops[0] == 0 ? 2 : 3;
        dp[0][1] = 1;

        for (int i = 1; i < n; i++) {

            dp[i][0] = tops[i] == 0 ?
                    (dp[i-1][0] * 2 + dp[i-1][1]) % MOD : (dp[i-1][0] * 3 + dp[i-1][1] * 2) % MOD;

            dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        }

        return (dp[n-1][0] + dp[n-1][1]) % MOD;
    }
}
