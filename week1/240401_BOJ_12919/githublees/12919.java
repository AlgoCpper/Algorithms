package backjoon;

import java.io.*;

public class BoJ_12919_A와_B_2 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String S = br.readLine();
		String T = br.readLine();
		
		System.out.println(dfs(S, new StringBuilder(T)) ? 1 : 0);
	}
	
	private static boolean dfs(String s, StringBuilder t) {
		
		if(s.length() == t.length()) {
			
			if(t.toString().equals(s)) {
				return true;				
			}
			
			return false;
		}

		/*
		 *  단어 T의 마지막 문자가 'A'이면 'A'를 삭제한다. 
		 */
		if(t.charAt(t.length()-1) == 'A' ) {
			
			t.deleteCharAt(t.length()-1);
			
			if(dfs(s, new StringBuilder(t))) {
				return true;
			}
			// 아래의 if문을 체크하기 위해 t를 원래 문자열로 돌림
			t.append("A");	
		}
		
		/*
		 * 단어 T의 처음 문자가 'B'이면 T를 뒤집고 'B'를 제거한다.
		 */
		if(t.charAt(0) == 'B') {
			
			t.reverse().deleteCharAt(t.length()-1);
			
			if(dfs(s, new StringBuilder(t))) {
				return true;
			}
		}
		
		return false;
	}
}
