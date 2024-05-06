package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BoJ_1707_이분_그래프 {

    static List<Integer>[] list;
    static int[][] edge;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int K = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < K; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int V = Integer.parseInt(st.nextToken());
            int E = Integer.parseInt(st.nextToken());

            list = new ArrayList[V+1];
            for (int i = 1; i < V+1; i++) {
                list[i] = new ArrayList<>();
            }

            for (int j = 1; j < E+1; j++) {
                st = new StringTokenizer(br.readLine());

                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());

                list[u].add(v);
                list[v].add(u);
            }

            String answer = "YES";
            int[] visited = new int[V+1];
            for (int i = 1; i < V+1; i++) {
                if (visited[i] == 0) {
                    if (!bfs(i, visited)) {
                        answer = "NO";
                        break;
                    }
                }
            }

            System.out.println(answer);
        }
    }

    private static boolean bfs(int i, int[] visited) {
        Queue<Integer> q = new LinkedList<>();

        visited[i] = 1;
        q.offer(i);

        while (!q.isEmpty()) {

            int v = q.poll();

            for (int nxt : list[v]) {
                if (visited[nxt] == visited[v]) {
                    return false;
                }
            }

            for (int nxt : list[v]) {
                if (visited[nxt] == 0) {
                    visited[nxt] = 3 - visited[v];
                    q.offer(nxt);
                }
            }
        }
        return true;
    }
}
