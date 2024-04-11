package backjoon;

import java.io.*;
import java.util.StringTokenizer;

public class BoJ_2343_기타_레슨 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
	
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int[] arr = new int[N];
		
		int start = 0;
		int end = 0;
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			
			// 강의 중 가장 큰 값
			start = Math.max(start, arr[i]);
			
			// 모든 강의의 합
			end += arr[i];
		}
	
		while(start <= end) {
			int mid = (start+end) / 2;
			int sum = 0;
			int bluray = 0; // 블루레이 수
			
			// 녹화 중인 강의 시간 계산
			for(int i=0; i<N; i++) {
				
				// 강의의 길이 합이 mid보다 커지면
				if(sum + arr[i] > mid) {
					// 새로운 블루레이를 위한 초기화
					sum = 0;
					bluray++;
				}
				
				// 아닐 시 계속 녹화
				sum += arr[i];
			}
			
			// 0이 아니라면 남은 강의가 존재하므로 bluray + 1;
			if(sum != 0) bluray++;
			
			// 블루레이 개수가 M보다 작거나 같다면 mid 줄이기
			// M 개수 내로 가능한 크기 중 최소를 구하기 위해서
			if(bluray <= M) end = mid - 1;
			
			// 블루레이 개수가 M보다 크다면 mid 늘리기
			// 지금 크기로는 M 개의 강의에 맞춰서 담을 수 없기 때문
			if(bluray > M) start = mid + 1;
		}
		
		System.out.println(start);
	}

}
