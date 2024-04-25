package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BoJ_14719_빗물 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] HW = br.readLine().split(" ");

        int H = Integer.parseInt(HW[0]);
        int W = Integer.parseInt(HW[1]);

        int[] block = new int[W];
        int[] rain = new int[W];

        int answer = 0;

        String[] str = br.readLine().split(" ");
        for (int i = 0; i < W; i++) {
            block[i] = Integer.parseInt(str[i]);
        }

        int height = 0;
        for (int i = 0; i < W; i++) {
            block[i] = Integer.parseInt(str[i]);
            height = Math.max(height, block[i]);
            rain[i] = height;
        }

        height = 0;
        for (int i = W-1; i >= 0; i--) {
            height = Math.max(height, block[i]);
            rain[i] = Math.min(rain[i], height);
            answer += (rain[i] - block[i]);
        }

        System.out.println(answer);
    }
}
