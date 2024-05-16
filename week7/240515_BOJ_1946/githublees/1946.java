package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class BoJ_1946_신입_사원 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {

            int N = Integer.parseInt(br.readLine());
            int[][] staff = new int[N][2];

            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                staff[i][0] = Integer.parseInt(st.nextToken());
                staff[i][1] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(staff, new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    return Integer.compare(o1[0], o2[0]);
                }
            });

            int answer = 0;
            int max = staff[0][1];

            for (int i = 1; i < N; i++) {
                if (max > staff[i][1]) {
                    answer++;
                    max = staff[i][1];
                }
            }
            System.out.println(answer + 1);
        }
    }
}
