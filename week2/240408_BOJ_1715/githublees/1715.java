package backjoon;

import java.io.*;
import java.util.PriorityQueue;

public class BoJ_1715_카드_정렬하기 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int answer = 0;
		
		int N = Integer.parseInt(br.readLine());
		
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(int i=0; i<N; i++) {
			pq.offer(Integer.parseInt(br.readLine()));
		}
		
		while(true) {
			
			if(pq.size() == 1) break;
			
			int A = pq.poll();
			int B = pq.poll();
			int C = A + B;
			
			answer += C;
			
			pq.offer(C);
		}
		
		System.out.println(answer);
	}
}
