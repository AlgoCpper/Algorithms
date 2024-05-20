package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class BoJ_1342_행운의_문자열 {

    static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        int[] alphabet = new int[26];

        for (int i = 0; i < str.length(); i++) {
            alphabet[str.charAt(i)-'a']++;
        }

        permutation(str, alphabet, -1, 0, str.length());

        System.out.println(answer);
    }

    private static void permutation(String str, int[] alphabet, int last, int depth, int r) {

        if (depth == r) {
            answer++;
            return;
        }

        for (int i = 0; i < 26; i++) {
            if (alphabet[i] <= 0 || i == last) continue;

            alphabet[i]--;
            permutation(str, alphabet, i, depth+1, r);
            alphabet[i]++;
        }
    }
}
