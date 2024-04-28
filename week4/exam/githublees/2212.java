package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class BoJ_2212_센서 {

    static int max = Integer.MIN_VALUE;
    static int min = Integer.MAX_VALUE;

    static int[] sensor;
    static int N;
    static int K;

    static int answer;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        sensor = new int[N];
        for (int i = 0; i < N; i++) {
            sensor[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(sensor);

        Integer[] dis = new Integer[N-1];
        for (int i = 0; i < N-1; i++) {
            dis[i] = sensor[i+1] - sensor[i];
        }

        Arrays.sort(dis, Comparator.reverseOrder());

        for (int i = K-1; i < N-1; i++) {
            answer += dis[i];
        }

        System.out.println(answer);
    }
}
