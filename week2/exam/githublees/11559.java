package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BoJ_11559_Puyo_Puyo {
	
	static char[][] map;
	
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};

	static class Puyo {
		int x;
		int y;
		
		public Puyo(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		map = new char[12][6];
		
		for(int i=0; i<12; i++) {
			map[i] = br.readLine().toCharArray();
		}
		
		int cnt = 0;
		
		while(true) {
			
			boolean isCheck = false;
			
			boolean[][] visit = new boolean[12][6];
			
			for(int i=map.length-1; i>=0; i--) {
				for(int j=0; j<6; j++) {
					
					if(visit[i][j] || map[i][j] == '.') continue;

					isCheck = bfs(visit, i, j, map[i][j], isCheck);
					
				}
			}
			
			if(!isCheck) break;
			
			mapChange(visit);
			cnt++;
		}
		
		System.out.println(cnt);
		
	}
	
	public static boolean bfs(boolean[][] v, int x, int y, char c, boolean check) {
		
		boolean[][] visited = new boolean[12][6];
		
		copyVisited(v, visited);
		
		visited[x][y] = true;

		Queue<Puyo> q = new LinkedList<>();
		
		q.offer(new Puyo(x, y));
		
		int cnt = 1;
		while(!q.isEmpty()) {
			
			Puyo p = q.poll();
			
			for(int d=0; d<4; d++) {
				int nx = p.x + dx[d];
				int ny = p.y + dy[d];
				
				if(nx < 0 || ny < 0 || nx >= map.length || ny >= map[nx].length || visited[nx][ny] || map[nx][ny] != c) continue;
				
				visited[nx][ny] = true;
				q.offer(new Puyo(nx, ny));
				cnt++;
			}
		}
		
		if(cnt >= 4) {
			copyVisited(visited, v);
			return true;
		}
		return check;
	}
	
	public static void mapChange(boolean[][] v) {
		for(int i=0; i<12; i++) {
			for(int j=0; j<6; j++) {
				if(v[i][j]) map[i][j] = '.';
			}
		}
		
		Stack<Character> stack = new Stack<>();
		for(int j=0; j<6; j++) {
			
			for(int i=map.length-1; i>=0; i--) {
				
				if(map[i][j] == '.') continue;
				
				stack.push(map[i][j]);
				map[i][j] = '.';
			}
			
			while(!stack.isEmpty()) {
				map[12-stack.size()][j] = stack.pop();
			}
		}
	}
	
	public static void copyVisited(boolean[][] bf, boolean[][] af) {
		for(int i=0; i<12; i++) {
			for(int j=0; j<6; j++) {
				af[i][j] = bf[i][j];
			}
		}
	}
}
