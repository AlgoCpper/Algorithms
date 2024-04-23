package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BoJ_1753_최단경로 {

    static List<Node>[] list;
    static int[] dp;
    static boolean[] check;

    static class Node implements Comparable<Node>{
        int to;
        int w;

        public Node(int to, int w) {
            this.to = to;
            this.w = w;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.w, o.w);
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(br.readLine());
        check = new boolean[V+1];
        dp = new int[V+1];
        list = new ArrayList[V+1];

        for (int i = 0; i < V+1; i++) {
            dp[i] = Integer.MAX_VALUE;
            list[i] = new ArrayList<>();
        }

        for (int i = 0; i < E; i++) {

            st = new StringTokenizer(br.readLine());

            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            list[u].add(new Node(v, w));
        }

        dijkstra(start);

        for (int i = 1; i < V+1; i++) {
            if(dp[i] == Integer.MAX_VALUE) {
                System.out.println("INF");
            } else {
                System.out.println(dp[i]);
            }
        }
    }

    private static void dijkstra(int start) {
        Queue<Node> pq = new PriorityQueue<>();

        pq.offer(new Node(start, 0));

        dp[start] = 0;

        while(!pq.isEmpty()) {
            Node n = pq.poll();

            if(check[n.to]) continue;
            else check[n.to] = true;

            for (Node nxt : list[n.to]) {
                if(dp[nxt.to] >= dp[n.to] + nxt.w) {
                    dp[nxt.to] = dp[n.to] + nxt.w;
                    pq.offer(new Node(nxt.to, dp[nxt.to]));
                }
            }
        }
    }
}
