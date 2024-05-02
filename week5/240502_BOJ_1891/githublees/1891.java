package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BoJ_1891_사분면 {

    static int d;
    static int[] num;
    static long tx, ty;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        d = Integer.parseInt(st.nextToken());
        num = new int[d];

        String str = st.nextToken();
        for (int i = 0; i < d; i++) {
            num[i] = str.charAt(i) - '0';
        }

        st = new StringTokenizer(br.readLine());
        long x = Long.parseLong(st.nextToken());
        long y = Long.parseLong(st.nextToken());

        long n = 1L << d; // 주어진 좌표평면의 한 변의 길이
        findLoc(0, 0, 0, n, n);
        tx -= y;
        ty += x;


        if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
            findNum(d, tx, ty);
        } else {
            System.out.println("-1");
        }

        System.out.println(sb.toString());
    }

    // 주어진 사분면 숫자의 위치 찾기
    private static void findLoc(int numIdx, long lx, long ly, long rx, long ry) {
        if (numIdx == d) {
            tx = lx;
            ty = ly;
            return;
        }

        int n = num[numIdx];
        if (n == 1) { // 1사분면
            findLoc(numIdx + 1, lx, (ly + ry) / 2, (lx + rx) / 2, ry);
        } else if (n == 2) { // 2사분면
            findLoc(numIdx + 1, lx, ly, (lx + rx) / 2, (ly + ry) / 2);
        } else if (n == 3) { // 3사분면
            findLoc(numIdx + 1, (lx + rx) / 2, ly, rx, (ly + ry) / 2);
        } else if (n == 4) { // 4사분면
            findLoc(numIdx + 1, (lx + rx) / 2, (ly + ry) / 2, rx, ry);
        }
    }

    // 주어진 위치로 사분면 찾기
    private static void findNum(int depth, long tx, long ty) {
        if (depth == 0) {
            return;
        }

        long half = 1L << (depth - 1); // 한변의 길이를 계속 반으로

        if (tx < half && ty >= half) {
            sb.append("1");
            findNum(depth - 1, tx, ty - half);

        } else if (tx < half && ty < half) {
            sb.append("2");
            findNum(depth - 1, tx, ty);

        } else if (tx >= half && ty < half) {
            sb.append("3");
            findNum(depth - 1, tx - half, ty);

        } else if (tx >= half && ty >= half) {
            sb.append("4");
            findNum(depth - 1, tx - half, ty - half);
        }
    }
}
