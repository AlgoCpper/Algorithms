package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.util.Arrays.stream;

public class BoJ_17136_색종이_붙이기 {

    static int[][] map = new int[10][10];
    static int[] paper = {0, 5, 5, 5, 5, 5};
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 10; i++) {
            map[i] = stream(br.readLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();
        }

        dfs(0, 0);
        System.out.println(answer == Integer.MAX_VALUE ? -1 : answer);
    }

    static void dfs(int idx, int cnt) {
        //완전탐색을 위해 0,0 ~ 10,10까지를 인덱스로 표현
        if (idx == 100) {
            answer = Math.min(cnt, answer);
            return;
        }

        //이미 나온 답보다 큰 경우 더이상의 탐색 불필요
        if(answer <= cnt)
            return;

        int x = idx / 10;
        int y = idx % 10;

        if (map[x][y] == 1) {
            //큰 색종이부터 사용하기
            for (int i = 5; i > 0; i--) {
                //색종이가 남아있고 && 색종이 부분이 다 1인경우
                if (paper[i]>0 && check(x,y, i)) {
                    //색종이 수 -1, 다음 탐색시 걸리지 않게 0으로 바꿈, 계속 탐색
                    paper[i] -= 1;
                    fill(x,y,i,0);
                    dfs(idx + 1, cnt + 1);
                    //탐색 후 되돌려줌
                    fill(x,y,i,1);
                    paper[i] += 1;
                }
            }
        } else {
            dfs(idx + 1, cnt);
        }
    }

    static void fill(int x,int y,int paperSize,int num) {
        for (int i = x; i< x + paperSize; i++) {
            for (int j = y; j < y + paperSize; j++) {
                map[i][j]=num;
            }
        }
    }

    static boolean check(int x, int y,int paperSize) {
        if (x + paperSize > 10 || y + paperSize > 10) {
            return false;
        }

        for (int i = x; i < x + paperSize; i++) {
            for (int j = y; j < y + paperSize; j++) {
                if (map[i][j] != 1) {
                    return false;
                }
            }
        }
        return true;
    }
}
