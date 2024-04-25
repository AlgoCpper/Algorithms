package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BoJ_2109_순회강연 {

    static int answer = 0;
    static boolean[] visit = new boolean[10001];

    static class Lecture implements Comparable<Lecture> {
        int p;
        int d;

        public Lecture(int p, int d) {
            this.p = p;
            this.d = d;
        }

        @Override
        public int compareTo(Lecture o) {
            if (this.p == o.p) {
                return this.d - o.d;
            }
            return o.p - this.p;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Lecture> pq = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int p = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            pq.offer(new Lecture(p, d));
        }

        while(!pq.isEmpty()) {

            Lecture l = pq.poll();

            for (int i = l.d; i > 0 ; i--) {

                if (!visit[i]) {
                   visit[i] = true;
                   answer += l.p;
                   break;
                }
            }
        }

        System.out.println(answer);
    }
}
