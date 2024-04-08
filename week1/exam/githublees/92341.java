package programers;

import java.util.*;

class Solution_92341 {
    public int[] solution(int[] fees, String[] records) {
        
        HashSet<Integer> car_list = new HashSet<>();
        
        boolean[] inOutCheck = new boolean[10000];
        int[] inOutTime = new int[10000];
        int[] totalTime = new int[10000];
            
        for(int i=0; i<records.length; i++) {
            String[] input = records[i].split(" ");
            
            // 시간 -> 분
            String[] time = input[0].split(":");
            int h = Integer.parseInt(time[0]) * 60;
            int m = Integer.parseInt(time[1]);
            int total = h + m;
            
            int car = Integer.parseInt(input[1]);
            
            car_list.add(car);
            
            if(input[2].equals("IN")) {
                inOutCheck[car] = true;
                inOutTime[car] = total; // 들어온 시간
                
            } else if(input[2].equals("OUT")) {
                inOutCheck[car] = false; // 출차 기록
                inOutTime[car] = (int) Math.abs(total - inOutTime[car]); // 이용시간
                totalTime[car] += inOutTime[car]; // 총 누적시간
                inOutTime[car] = 0; // 이용시간 초기화
                
            }
        }
        
        int[] answer = new int[car_list.size()];
        
        int idx = -1;
        for(int c : car_list) {
                answer[++idx] = c;
        }
        
        Arrays.sort(answer);
        
        for(int i=0; i<answer.length; i++) {
            
            if(inOutCheck[answer[i]]) {
                totalTime[answer[i]] += 1439 - inOutTime[answer[i]];
            }
            
            if(totalTime[answer[i]] <= fees[0]) {
                answer[i] = fees[1];
            } else {
                answer[i] = fees[1] + (int) Math.ceil(Math.abs((double) (totalTime[answer[i]] - fees[0]) / fees[2] )) * fees[3];
                
            }
            
            
        } 
        
        return answer;
    }
}