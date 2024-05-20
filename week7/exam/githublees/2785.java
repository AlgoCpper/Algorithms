package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class BoJ_2785_체인 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int answer = 0;
        int N = Integer.parseInt(br.readLine());
        List<Integer> chain = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            chain.add(Integer.parseInt(st.nextToken()));
        }

        Collections.sort(chain);

        while (true) {
            if (chain.size() <= 1) {
                break;
            }

            chain.set(0, chain.get(0)- 1);
            chain.remove(chain.size() - 1);

            if (chain.get(0) == 0) {
                chain.remove(0);
            }

            answer++;
        }

        System.out.println(answer);
    }
}
