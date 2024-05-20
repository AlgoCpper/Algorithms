import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;
        int length = friends.length;
        
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < length; i++) {
            String str = friends[i];
            map.put(str, i);
        }
        
        int[][] giveTake = new int[length][length];
        int[] giftIndex = new int[length];
        
        for (String gift : gifts) {
            String[] split = gift.split(" ");
            String give = split[0];
            String take = split[1];
            
            int giveIdx = map.get(give);
            int takeIdx = map.get(take);
            
            giveTake[giveIdx][takeIdx]++;
            giftIndex[giveIdx]++;
            giftIndex[takeIdx]--;
        }
        
        for (int i = 0; i < length; i++) {
            int cnt = 0;
            for (int j = 0; j < length; j++) {
                if (i == j) continue;
                
                if (giveTake[i][j] > giveTake[j][i]) cnt++;
                else if (giveTake[i][j] == giveTake[j][i] && giftIndex[i] > giftIndex[j]) cnt++;
            }
            if (cnt > answer) answer = cnt;
        }
        
        return answer;
    }
}