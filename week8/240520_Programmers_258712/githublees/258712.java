package programmers;

import java.util.HashMap;
import java.util.Map;

public class Pro_258712_가장_많이_받은_선물 {
    static Map<String, Friend> info;

    static class Friend {

        // 선물지수
        int total;

        // 다음 달에 받는 선물
        int next;

        // 내가 선물 준 애들 정보
        Map<String, Integer> send = new HashMap<>();

        // 나에게 선물 준 애들 정보
        Map<String, Integer> receive = new HashMap<>();

        public Friend() {
        }

        //주는 과정
        public void fromTo(String receiver) {
            this.total += 1;
            this.send.put(receiver, send.getOrDefault(receiver, 0) + 1);
        }

        //받는 과정
        public void toFrom(String sender) {
            this.total -= 1;
            this.receive.put(sender, receive.getOrDefault(sender, 0) + 1);
        }

        public int nextMonthGift(String receiver) {

            // 내가 상대방에게 준 선물 갯수
            int r = send.getOrDefault(receiver, 0);
            // 상대방이 나에게 준 선물 갯수
            int s = receive.getOrDefault(receiver, 0);

            if (r > s) {
                this.next += 1;

            } else if (r == s) {
                this.next += this.total > info.getOrDefault(receiver, new Friend()).total ? 1 : 0;

            }

            return this.next;

        }

    }

    public static int solution(String[] friends, String[] gifts) {
        int answer = 0;

        info = new HashMap<>();

        for (int i = 0; i < gifts.length; i++) {

            String[] input = gifts[i].split(" ");

            Friend sender = info.getOrDefault(input[0], new Friend());
            Friend receiver = info.getOrDefault(input[1], new Friend());

            sender.fromTo(input[1]);
            receiver.toFrom(input[0]);

            info.put(input[0], sender);
            info.put(input[1], receiver);
        }

        for (String f1 : info.keySet()) {

            Friend friend = info.get(f1);

            for (String f2 : friends) {

                if (f1.equals(f2)) continue;

                answer = Math.max(answer, friend.nextMonthGift(f2));
            }
        }

        return answer;
    }
}
