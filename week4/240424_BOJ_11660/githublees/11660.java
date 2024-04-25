package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BoJ_11660_구간_합_구하기_5 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] table = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < N; j++) {
                table[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] prefixSum = new int[N+1][N+1];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                prefixSum[i][j] = table[i-1][j-1] + prefixSum[i][j-1] + prefixSum[i-1][j] - prefixSum[i-1][j-1];
            }
        }

        for (int i = 0; i < M; i++) {

            st = new StringTokenizer(br.readLine());

            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            prefix(prefixSum, x1, y1, x2, y2);

        }
    }

    private static void prefix(int[][] prefixSum, int x1, int y1, int x2, int y2) {

        int answer = prefixSum[x2][y2] + prefixSum[x1-1][y1-1] - prefixSum[x1-1][y2] - prefixSum[x2][y1-1];

        System.out.println(answer);
    }
}
