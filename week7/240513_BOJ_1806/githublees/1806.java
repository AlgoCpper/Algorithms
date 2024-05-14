package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BoJ_1806_부분합 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int[] input = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            input[i] = Integer.parseInt(st.nextToken());
        }

        int start = 0;
        int end = 0;
        int sum = 0;
        int answer = 100000;

        while (start < N && end < N) {
            if (sum < S) {
                sum += input[start++];
            }

            while (sum >= S) {
                sum -= input[end++];
                answer = Math.min(answer, (start - end) + 1);
            }
        }

        if (answer == 100000) {
            System.out.println(0);
        } else {
            System.out.println(answer);
        }
    }
}
