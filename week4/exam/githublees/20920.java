package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BoJ_20920_영단어_암기는_괴로워 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        Map<String, Integer> wordList = new HashMap<>();

        for (int i = 0; i < N; i++) {
            String word = br.readLine();
            if (word.length() >= M) {
                wordList.put(word, wordList.getOrDefault(word, 0)+1);
            }
        }

        PriorityQueue<String> pq = new PriorityQueue<>(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (wordList.get(o1) > wordList.get(o2)) {
                    return -1;

                } else if (wordList.get(o1) < wordList.get(o2)) {
                    return 1;

                } else {
                    if (o1.length() > o2.length()) {
                        return -1;
                    } else if (o1.length() < o2.length()) {
                        return 1;
                    } else {
                        return o1.compareTo(o2);
                    }
                }
            }
        });

        for (String s : wordList.keySet()) {
            pq.offer(s);
        }

        print(pq);

    }

    private static void print(PriorityQueue<String> pq) {
        StringBuilder sb = new StringBuilder();
        while (!pq.isEmpty()) {

            String str = pq.poll();

            sb.append(str).append("\n");
        }
        System.out.println(sb.toString());
    }
}
