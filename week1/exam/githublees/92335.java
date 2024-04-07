package programers;

import java.util.*;

class Solution_92335 {
    public int solution(int n, int k) {
        int answer = 0;
        
        StringBuilder sb = new StringBuilder();
       
        while(n > 0) {
            sb.append(n % k);
            n /= k;
        }
        sb.reverse();
        
        String[] prime = sb.toString().split("0");
        ArrayList<Long> p_list = new ArrayList<>();
        
        for(int i=0; i<prime.length; i++) {
            if(prime.equals(" ") || prime[i].equals("") || Long.parseLong(prime[i]) == 1) continue;
            p_list.add(Long.parseLong(prime[i]));
        }
        
        for(int i=0; i<p_list.size(); i++) {
            
            long p = p_list.get(i);
            
            boolean isPrime = true;
            for(int j=2; j<=Math.sqrt(p); j++) {
                if(p%j == 0) {
                    isPrime = false;
                    break;
                }
            }
           
            
            if(isPrime) answer++;
        }
        
        return answer;
    }
}