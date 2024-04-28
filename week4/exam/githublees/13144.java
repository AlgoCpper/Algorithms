package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BoJ_13144_List_of_Unique_Numbers {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        long answer = 0;
        int[] number = new int[100001];
        int[] input = new int[N+1];

        for (int i = 1; i <= N; i++) {
            input[i] = Integer.parseInt(st.nextToken());
        }

        int start = 1;
        int end = 1;

       while (start <= N) {

            while (end <= N && number[input[end]] == 0) {
                number[input[end]]++;
                end++;
            }

            answer += (end - start);

            number[input[start++]]--;
        }
        System.out.println(answer);
    }
}
