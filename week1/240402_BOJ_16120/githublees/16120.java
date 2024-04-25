package backjoon;

import java.io.*;
import java.util.Stack;

public class BoJ_16120_PPAP {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		char[] chArr = br.readLine().toCharArray();
		Stack<Character> stack = new Stack<>();

		for(int i=0; i<chArr.length; i++) {

			if(stack.isEmpty()) {

				stack.push(chArr[i]);

			} else {
				// stack 마지막에 들어간 값이 'A'이고
				if(stack.peek() == 'A') {

					StringBuilder ppap = new StringBuilder().append(chArr[i]);

					// stack 이 비어있지 않고, ppap 가 "PPAP" 길이보다 작은 동안
					while(!stack.isEmpty() && ppap.length() < 4) {

						// stack.pop()한 값을 ppap 앞에 붙인다.
						ppap.insert(0, stack.pop());

					}

					// ppap가 "PPAP"라면
					if(ppap.toString().equals("PPAP")) {

						stack.push('P');

					} else {

						// 아니라면 꺼냈던 값을 다시 stack에 넣는다.
						for(int j=0; j<ppap.length(); j++) {

							stack.push(ppap.charAt(j));

						}
					}

				} else {

					stack.push(chArr[i]);

				}
			}
		}

		System.out.println(stack.peek() == 'P' && stack.size() == 1 ? "PPAP" : "NP");
	}
}
