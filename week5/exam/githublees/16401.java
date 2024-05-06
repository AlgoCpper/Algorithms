package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BoJ_16401_과자_나눠주기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int[] snack = new int[N];
        long result = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            snack[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(snack);

        long left = 1;
        long right = snack[N-1];

        while (left <= right) {
            int count = 0;
            long mid = (right + left) / 2;

            // 막대 과자 길이를 특저한 뒤 몇명의 조카에게 줄 수 있는지 계산
            for (int i = 0; i < N; i++) {
                count += snack[i] / mid;
            }

            // 조카의 수보다 막대 과자가 많이 나오면 해다 길이만큼 나눠줄 수 있음
            // 계속 반복하면서 범위를 좁혀나가고, 막대 과자의 길이를 최대로 특정
            if (count >= M) {
                if (result < mid) result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        System.out.println(result);
    }
}
