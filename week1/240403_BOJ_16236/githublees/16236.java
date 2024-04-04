package backjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BoJ_16236_아기_상어 {
	
	static int start_x;
	static int start_y;

	static int[] dx = {-1, 0, 0, 1};
	static int[] dy = {0, -1, 1, 0};
	
	static class Shark {
		int x;
		int y;
		int dist;
		
		public Shark(int x, int y, int dist) {
			this.x = x;
			this.y = y;
			this.dist = dist;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		
		int[][] map = new int[N][N];

		for(int i=0; i<N; i++) {		
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				
				if(map[i][j] == 9) { 
					start_x = i;
					start_y = j;
					map[i][j] = 0;
				}
			}			
		}
		
		int size = 2; // 상어 현재 크기
		int eat = 0;  // 먹은 물고기 수
		int dist = 0; // 이동거리(걸린 시간)
		
		while(true) {
			
			// 먼저 먹어야되는 먹이 오름차순 정렬, 우선적으로 거리 -> x축 -> y축
			PriorityQueue<Shark> pq = new PriorityQueue<>((o1, o2) -> 
				o1.dist != o2.dist ? Integer.compare(o1.dist, o2.dist) : 
					(o1.x != o2.x ? Integer.compare(o1.x, o2.x) : Integer.compare(o1.y, o2.y))
			);
			
			pq.offer(new Shark(start_x, start_y, 0));
			
			boolean[][] visit = new boolean[N][N];
			visit[start_x][start_y] = true;
						
			boolean isCheck = false; // 상어가 먹이를 먹었는지?
			
			while(!pq.isEmpty()) {
				
				Shark shark = pq.poll();
				
				// 먹이가 있으면서 상어보다 작은 사이즈면
				if(map[shark.x][shark.y] != 0 && map[shark.x][shark.y] < size) {
					map[shark.x][shark.y] = 0;
					
					// 현재 먹은 위치부터 다시 우선 순위 큐를 돌기 위해 초기화
					start_x = shark.x;
					start_y = shark.y;
					
					// 먹은 물고기 +1
					eat++;
					
					// 먹이까지의 이동 거리를 총 이동거리에 더하기
					dist += shark.dist;
					
					isCheck = true;
					break;
				}
				
				// 상어의 이동을 위한 for문
				for(int d=0; d<4; d++) {
					int nx = shark.x + dx[d];
					int ny = shark.y + dy[d];
					
					if(nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] || map[nx][ny] > size) continue;
					
					pq.offer(new Shark(nx, ny, shark.dist + 1));
					visit[nx][ny] = true;
				}
			}
			
			// 큐를 다 도는 동안 먹이를 먹지 못했다면 while문 빠져나오기 
			if(!isCheck) break;
			
			// 상어가 자신의 사이즈 만큼 먹이를 먹었다면 size +1
			if(size == eat) {
				size++;
				eat = 0;
			}
		}
		
		System.out.println(dist);
	}
}
