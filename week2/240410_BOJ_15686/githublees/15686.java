package backjoon;

import java.io.*;
import java.util.*;

public class BoJ_15686_치킨_배달 {
	
	static int result = Integer.MAX_VALUE;
	
	static ArrayList<Chicken> chickenList;
	static ArrayList<House> houseList;
	
	static class House {
		int x;
		int y;
		
		public House(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static class Chicken {
		int x;
		int y;
		
		public Chicken(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
				
		Chicken[] selectedChicken = new Chicken[M];
		
		chickenList = new ArrayList<>();
		houseList = new ArrayList<>();
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<N; j++) {
				
				int n = Integer.parseInt(st.nextToken());
				
				if(n == 1) 
					houseList.add(new House(i, j));
				else if(n == 2) 
					chickenList.add(new Chicken(i, j));
			}
		}
		
		SelectedChickenRestaurant(selectedChicken, 0, 0, M);
		
		System.out.println(result);
	}

	// 모든 치킨집에서 M개를 뽑는 함수
	private static void SelectedChickenRestaurant(Chicken[] sc, int start, int depth, int m) {
		if(depth == m) {
			
			CalculateDistance(sc);
			
			return;
		}
		
		for(int i=start; i<chickenList.size(); i++) {
			sc[depth] = chickenList.get(i);
			SelectedChickenRestaurant(sc, i+1, depth+1, m);
		}
	}

	// 뽑은 치킨집과 집 간의 최소 거리 계산 
	private static void CalculateDistance(Chicken[] sc) {
		
		int sum = 0;
		
		for(int i=0; i<houseList.size(); i++) {
			int min = Integer.MAX_VALUE;
			
			for(int j=0; j<sc.length; j++) {
				min = Math.min( min, (int)(Math.abs(houseList.get(i).x - sc[j].x) + Math.abs(houseList.get(i).y - sc[j].y)) );
			}
			
			sum += min;
		}
		
		result = Math.min(result, sum);
	}
}
