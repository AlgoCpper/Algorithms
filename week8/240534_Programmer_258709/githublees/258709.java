package programmers;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Pro_258709_주사위_고르기 {

    private static int n;
    private static List<int[]> diceComb = new ArrayList();

    public int[] solution(int[][] dice) {
        n = dice.length;

        // n / 2개의 주사위를 선택하는 조합을 구한다.
        combineDice(0, 0, new int[n / 2]);

        int[] answer = {};
        int maxWinCnt = 0;

        for (int[] aComb : diceComb) {
            List<Integer> aScores = new ArrayList<>();
            // A의 주사위로 얻을 수 있는 점수를 구한다.
            combineScores(0, 0, aComb, aScores, dice);
            Collections.sort(aScores);

            int[] bComb = getBComb(aComb);
            List<Integer> bScores = new ArrayList<>();
            // B의 주사위로 얻을 수 있는 점수를 구한다.
            combineScores(0, 0, bComb, bScores, dice);
            Collections.sort(bScores);

            // A가 몇 번 이기는지 구한다.
            int winCnt = getWinCntOfA(aScores, bScores);
            if (maxWinCnt < winCnt) {
                maxWinCnt = winCnt;
                answer = aComb;
            }
        }

        // 현재 주사위 번호가 0부터 시작하기 때문에 1씩 더해준다.
        for (int i = 0; i < answer.length; i++) {
            answer[i]++;
        }

        return answer;
    }

    private void combineDice(int start, int cnt, int[] numbers) {
        // n / 2개의 주사위를 모두 골랐을 경우 주사위 번호 조합을 리스트에 추가한다.
        if (cnt == n / 2) {
            diceComb.add(numbers.clone());
            return;
        }

        for (int i = start; i < n; i++) {
            numbers[cnt] = i;
            combineDice(i + 1, cnt + 1, numbers);
        }
    }

    // B가 가져간 나머지 n / 2개의 주사위 번호를 가져온다.
    private int[] getBComb(int[] aComb) {
        boolean[] isA = new boolean[n];
        for (int num : aComb) {
            // A가 가져간 주사위 번호를 true 처리한다.
            isA[num] = true;
        }

        int b = 0;
        int[] bComb = new int[n / 2];
        for (int i = 0; i < n; i++) {
            if (!isA[i]) {
                bComb[b] = i;
                b++;
            }
        }

        return bComb;
    }

    private void combineScores(int cnt, int sum, int[] comb, List<Integer> scores, int[][] dice) {
        // n / 2개의 주사위를 모두 굴렸을 경우 나오는 점수를 리스트에 추가한다.
        if (cnt == n / 2) {
            scores.add(sum);
            return;
        }

        for (int i = 0; i < 6; i++) {
            combineScores(cnt + 1, sum + dice[comb[cnt]][i], comb, scores, dice);
        }
    }

    private int getWinCntOfA(List<Integer> aScores, List<Integer> bScores) {
        int winCnt = 0;

        // 이분 탐색하여 A의 점수로 이길 수 있는 B의 점수의 개수를 구한다.
        for (int s : aScores) {
            int start = 0;
            int end = bScores.size() - 1;

            while (start <= end) {
                int mid = (start + end) / 2;

                if (s > bScores.get(mid)) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            winCnt += start;
        }

        return winCnt;
    }
}
