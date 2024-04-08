package programers;

import java.util.*;

class Solution_92334 {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        
        // 신고 당한 횟수
        Map<String, Integer> user = new HashMap<>();
        
        // 신고한 유저, 신고 당한 유저
        Map<String, HashSet<String>> info = new HashMap<>();
        
        for(int i=0; i<report.length; i++) {
            String[] toFrom = report[i].split(" ");
            
            HashSet<String> set = info.getOrDefault(toFrom[0], new HashSet<>());
            
            set.add(toFrom[1]);
            
            info.put(toFrom[0], set);
        }
        
        for(String to : info.keySet()) {
            for(String from : info.get(to)) {
                user.put(from, user.getOrDefault(from, 0) + 1);
            }
        }
        
        for(int i=0; i<id_list.length; i++) {
            HashSet<String> temp = info.getOrDefault(id_list[i] , null);
            
            if(temp != null) {
                for(String f : temp) {
                    answer[i] += user.get(f) >= k ? 1 : 0;
                }
            } else {
                answer[i] += 0;
            }
        }
        
        return answer;
    }
}