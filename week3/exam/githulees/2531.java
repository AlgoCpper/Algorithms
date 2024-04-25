package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BoJ_2531_회전_초밥 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); // 접시 수
        int d = Integer.parseInt(st.nextToken()); // 초밥 가짓수
        int k = Integer.parseInt(st.nextToken()); // 연속해서 먹는 접시 수
        int c = Integer.parseInt(st.nextToken()); // 쿠폰 번호

        int[] belt = new int[N];
        int[] sushi = new int[d + 1];

        for (int i = 0; i < N; i++) {
            belt[i] = Integer.parseInt(br.readLine());
        }

        int count = 0;

        for (int i = 0; i < k; i++) {

            if (sushi[belt[i]]++ == 0) {
                count++;
            }
        }

        int eat = count;

        for (int i = 0; i < N; i++) {

            if (eat <= count) {
                if (sushi[c] == 0) {
                    eat = count + 1;
                } else {
                    eat = count;
                }
            }

            int start = i;
            if (--sushi[belt[start]] == 0) {
                count--;
            }

            int end = (i + k) % N;
            if (sushi[belt[end]]++ == 0) {
                count++;
            }
        }

        System.out.println(eat);
    }
}
