import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        String[] split = input.split(" ");

        int n = Integer.parseInt(split[0]);
        int m = Integer.parseInt(split[1]);

        Map<String, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            if (s.length() < m) continue;

            if (!map.containsKey(s)) {
                map.put(s, 1);
            } else {
                map.put(s, map.get(s) + 1);
            }
        }

        List<Map.Entry<String, Integer>> list = new ArrayList<>(map.entrySet());

        list.sort((e1, e2) -> {
            if (!Objects.equals(e1.getValue(), e2.getValue())) return e2.getValue() - e1.getValue();
            if (e1.getKey().length() != e2.getKey().length()) return e2.getKey().length() - e1.getKey().length();
            return e1.getKey().compareTo(e2.getKey());
        });

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (Map.Entry<String, Integer> entry : list) {
            bw.write(entry.getKey() + "\n");
        }

        bw.flush();
    }
}