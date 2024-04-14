package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BoJ_1253_좋다 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int answer = 0;

        for (int i = 0; i < N; i++) {
            int start = 0;
            int end = N-1;

            while(start < end) {

                if(end == i) end--;
                else if(start == i) start++;
                else {
                    if(arr[i] < arr[start] + arr[end]) {
                        end--;
                    } else if(arr[i] > arr[start] + arr[end]) {
                        start++;
                    } else if(arr[i] == arr[start] + arr[end]) {
                        answer++;
                        break;
                    }
                }
            }
        }

        System.out.println(answer);
    }
}
