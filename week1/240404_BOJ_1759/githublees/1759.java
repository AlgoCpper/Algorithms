package backjoon;

import java.io.*;
import java.util.*;

public class BoJ_1759_암호_만들기 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int L = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		
		ArrayList<String> alphabet = new ArrayList<>();
		StringBuilder pwd = new StringBuilder();
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<C; i++) {
			alphabet.add(st.nextToken());
		}
		
		// 입력받은 알파벳 사전 정렬
		Collections.sort(alphabet);
		
		combination(alphabet, pwd, 0, L, C, 0);
		         
	}
	
	private static void combination(ArrayList<String> alphabet, StringBuilder pwd, int start, int depth, int c, int r) {
		
		if(depth == r) {
			if(vowelsConsonantCheck(pwd)) { 
				System.out.println(pwd.toString());
			}
			
			return;
		}
		
		for(int i=start; i<c; i++) {
			pwd.append(alphabet.get(i));
			combination(alphabet, pwd, i+1, depth, c,r+1);
			pwd.deleteCharAt(pwd.length()-1);
		}
	}
	
	// 자음, 모음 갯수 체크를 위한 메서드
	private static boolean vowelsConsonantCheck(StringBuilder sb) {
		
		int vo = 0;
		
		for(int i=0; i<sb.length(); i++) {
			if(sb.charAt(i) == 'a' || sb.charAt(i) == 'e' || sb.charAt(i) == 'i' || sb.charAt(i) == 'o' || sb.charAt(i) == 'u') {
				vo++;
			}
		}
		
		if(vo >= 1 && sb.length() - vo >= 2) {
			return true;			
		}
		
		return false;
	}
}
