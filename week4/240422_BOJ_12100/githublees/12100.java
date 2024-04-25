package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BoJ_12100_2048_Easy {

    static int answer = Integer.MIN_VALUE;
    static int N;
    static int[][] board;
    static int[] move;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        move = new int[5];
        board = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        permutation(0);
        System.out.println(answer);

    }

    private static void permutation(int depth) {
        if(depth == 5) {
            boardChange();
            return;
        }

        for (int i = 0; i < 4; i++) {
            move[depth] = i;
            permutation(depth+1);
        }
    }

    private static void boardChange() {

        int[][] bc = new int[N][N];
        for (int i = 0; i < N; i++) {
            bc[i] = board[i].clone();
        }

        for (int i = 0; i < 5; i++) {

            if (move[i] == 0) { //상

                for (int y = 0; y < N; y++) {

                    Queue<Integer> q = new LinkedList<>();

                    for(int x = 0; x < N; x++) {

                        if(bc[x][y] == 0) continue;

                        q.offer(bc[x][y]);
                        bc[x][y] = 0;
                    }

                    int x = 0;
                    while(!q.isEmpty()) {

                        int first = q.poll();

                        if (q.isEmpty()) {
                            bc[x][y] = first;
                            break;

                        } else if (first == q.peek()) {
                            bc[x++][y] = first + q.poll();

                        } else if (first != q.peek()) {
                            bc[x++][y] = first;
                        }
                    }
                }

            } else if (move[i] == 1) { //하

                for (int y = 0; y < N; y++) {

                    Queue<Integer> q = new LinkedList<>();

                    for(int x = N-1; x >= 0; x--) {

                        if(bc[x][y] == 0) continue;

                        q.offer(bc[x][y]);
                        bc[x][y] = 0;
                    }

                    int x = N-1;
                    while(!q.isEmpty()) {

                        int first = q.poll();

                        if (q.isEmpty()) {
                            bc[x][y] = first;
                            break;

                        } else if (first == q.peek()) {
                            bc[x--][y] = first + q.poll();

                        } else if (first != q.peek()) {
                            bc[x--][y] = first;
                        }
                    }
                }

            } else if (move[i] == 2) { //좌

                for (int x = 0; x < N; x++) {

                    Queue<Integer> q = new LinkedList<>();

                    for(int y = 0; y < N; y++) {

                        if(bc[x][y] == 0) continue;

                        q.offer(bc[x][y]);
                        bc[x][y] = 0;
                    }

                    int y = 0;
                    while(!q.isEmpty()) {

                        int first = q.poll();

                        if (q.isEmpty()) {
                            bc[x][y] = first;
                            break;

                        } else if (first == q.peek()) {
                            bc[x][y++] = first + q.poll();

                        } else if (first != q.peek()) {
                            bc[x][y++] = first;
                        }
                    }
                }

            } else if (move[i] == 3) { //우

                for (int x = 0; x < N; x++) {

                    Queue<Integer> q = new LinkedList<>();

                    for(int y = N-1; y >= 0; y--) {

                        if(bc[x][y] == 0) continue;

                        q.offer(bc[x][y]);
                        bc[x][y] = 0;
                    }

                    int y = N-1;
                    while(!q.isEmpty()) {

                        int first = q.poll();

                        if (q.isEmpty()) {
                            bc[x][y] = first;
                            break;

                        } else if (first == q.peek()) {
                            bc[x][y--] = first + q.poll();

                        } else if (first != q.peek()) {
                            bc[x][y--] = first;
                        }
                    }
                }
            }

            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    answer = Math.max(answer, bc[j][k]);
                }
            }
        }
    }
}
