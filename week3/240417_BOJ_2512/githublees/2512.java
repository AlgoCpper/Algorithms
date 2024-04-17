package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BoJ_2512_예산 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] budget = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            budget[i] = Integer.parseInt(st.nextToken());
        }

        int M = Integer.parseInt(br.readLine());

        Arrays.sort(budget);

        budgetBinarySearch(budget, 0, budget[budget.length-1], M);
    }

    private static void budgetBinarySearch(int[] budget, int low, int high, int m) {

        while(low <= high) {
            int mid = (low + high) / 2;
            long total = totalBudget(budget, mid);

            if(total <= m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        System.out.println(high);
    }

    private static long totalBudget(int[] budget, int mid) {
        return Arrays.stream(budget).map(x -> x > mid ? mid : x).sum();
    }
}
