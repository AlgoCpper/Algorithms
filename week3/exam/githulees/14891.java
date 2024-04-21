package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class BoJ_14891_톱니바퀴 {

    static Gear[] gears;
    static int K;

    static class Gear {
        int[] gear;
        Gear leftGear;
        Gear rightGear;

        public Gear(int[] gear, Gear leftGear, Gear rightGear) {
            this.gear = gear.clone();
            this.leftGear = leftGear;
            this.rightGear = rightGear;
        }

        private void rotation(int direction, Gear progress) {

            // 반시계 방향 회전
            if (direction == -1) {

                relayGear(direction, progress);

            // 시계 방향 회전
            } else if (direction == 1) {

                relayGear(direction, progress);
            }

            //움직인 후 상태 변환
            statusChange(direction);
        }

        //기어 움직임 전달
        private void relayGear(int direction, Gear progress) {
            if (leftGear != null && !leftGear.equals(progress)) {
                if (leftGear.gear[2] != this.gear[6]) {
                    leftGear.rotation(direction * -1, this);
                }
            }
            if (rightGear != null && !rightGear.equals(progress)) {
                if (rightGear.gear[6] != this.gear[2]) {
                    rightGear.rotation(direction * -1, this);
                }
            }
        }

        private void statusChange(int direction) {
            if (direction == -1) {
                int temp = gear[0];
                for (int i = 1; i < 8; i++) {
                    gear[i-1] = gear[i];
                }
                gear[7] = temp;
            } else {
                int temp = gear[7];
                for (int i = 7; i > 0; i--) {
                    gear[i] = gear[i-1];
                }
                gear[0] = temp;
            }
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        int[] input = new int[8];
        gears = new Gear[4];

        for (int i = 0; i < 4; i++) {

            input = Arrays.stream(br.readLine().split(""))
                        .mapToInt(Integer::parseInt)
                        .toArray();

            gears[i] = new Gear(input, null, null);
        }

        //기어 초기화
        for (int i = 0; i < 4; i++) {
            if(i == 0) {
                gears[i].leftGear = null;
                gears[i].rightGear = gears[1];
            }

            if(i == 1) {
                gears[i].leftGear = gears[0];
                gears[i].rightGear = gears[2];
            }

            if(i == 2) {
                gears[i].leftGear = gears[1];
                gears[i].rightGear = gears[3];
            }

            if(i == 3) {
                gears[i].leftGear = gears[2];
                gears[i].rightGear = null;
            }
        }

        K = Integer.parseInt(br.readLine());

        for (int i = 0; i < K; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int num = Integer.parseInt(st.nextToken());
            int direction = Integer.parseInt(st.nextToken());

            gears[num-1].rotation(direction, gears[num-1]);
        }

        int answer = 0;

        answer += gears[0].gear[0] == 0 ? 0 : 1;
        answer += gears[1].gear[0] == 0 ? 0 : 2;
        answer += gears[2].gear[0] == 0 ? 0 : 4;
        answer += gears[3].gear[0] == 0 ? 0 : 8;

        System.out.println(answer);
    }
}
