import java.io.*;
import java.util.Stack;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		char[] chArr = br.readLine().toCharArray();

		Stack<Character> stack = new Stack<>();
		
		for(int i=0; i<chArr.length; i++) {
			if(stack.isEmpty()) {
				stack.push(chArr[i]);
				
			} else {
				
				if(stack.peek() == 'A') {
					
					StringBuilder ppap = new StringBuilder().append(chArr[i]);
					
					while(!stack.isEmpty() && ppap.length() < 4) {
						ppap.insert(0, stack.pop());
					}
					
					if(ppap.toString().equals("PPAP")) {
						stack.push('P');
						
					} else {
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