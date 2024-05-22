package programmers;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Pro_258711_도넛과_막대_그래프 {

    public int[] solution(int[][] edges) {
        Map<Integer, int[]> node = new HashMap<>();
        int[] answer = {0, 0, 0, 0};

        Arrays.stream(edges).forEach(edge -> {
            int a = edge[0];
            int b = edge[1];

            node.put(a, node.getOrDefault(a, new int[]{0, 0}));
            node.put(b, node.getOrDefault(b, new int[]{0, 0}));

            node.get(a)[0]++;
            node.get(b)[1]++;
        });

        node.entrySet().stream().forEach(entry -> {
            int key = entry.getKey();
            int[] cnt = entry.getValue();

            // 들어오는 간선이 없고 나가는 간선이 2개 이상이면 생성한 정점
            if (cnt[0] >= 2 && cnt[1] == 0) {
                answer[0] = key;

                // 나가는 간선이 없으면 막대 그래프 정점
            } else if (cnt[0] == 0) {
                answer[2]++;

                // 들어오는 간선이 2개 이상, 나가는 간선이 2개 이상이면 8자 그래프 정점
            } else if (cnt[0] >= 2 && cnt[1] >= 2) {
                answer[3]++;
            }
        });

        // 정점에서 출발한 간선갯수 - 직선 그래프 갯수 - 8자 그래프 갯수
        answer[1] = node.get(answer[0])[0] - answer[2] - answer[3];


        return answer;
    }
}
