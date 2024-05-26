package programmers;

import java.util.HashSet;
import java.util.Set;

public class Pro_258707_n_1_카드게임 {
    private static Set<Integer> myCards = new HashSet<>();
    private static Set<Integer> tempCards = new HashSet<>();
    private static int pair;
    private static int round = 1;
    private static int myCoin;
    private static int n;

    public int solution(int coin, int[] cards) {

        myCoin = coin;
        n = cards.length;

        // (1) 카드 n / 3장을 먼저 뽑는다.
        for (int i = 0; i < n / 3; i++) {
            myCards.add(cards[i]);
        }

        // (2) 처음에 뽑은 카드 중에서 페어 개수를 구한다.
        for (int card : myCards) { // (2)
            if (myCards.contains(n + 1 - card)) {
                pair++;
            }
        }
        pair /= 2;

        // (3) 카드 뭉치를 두 장씩 순회한다.
        for (int i = n / 3; i < n; i += 2) {

            // (4) 뽑은 두 개의 카드를 처음에 뽑은 카드와 페어가 되는지 확인한다.
            matchCard(cards[i]);
            matchCard(cards[i + 1]);

            // (5) 페어가 없고 코인이 2개 이상이면 구매하지 않고
            // 넘긴 카드 중에서 페어가 되는 카드 2개를 구매한다.
            if (pair < 1 && myCoin > 1) {
                for (int card : tempCards) {
                    if (tempCards.contains(n + 1 - card)) {
                        pair++;
                        myCoin -= 2;
                        // (6) 임의의 수와 다른 수를 합해서 n + 1이 되는 경우는 하나뿐이므로
                        // 페어가 되는 카드 중 하나를 삭제해서 다음에 또 구매하지 않도록 한다.
                        tempCards.remove(card);

                        break;
                    }
                }
            }

            // (7) 페어가 없으면 다음 라운드를 진행할 수 없기 때문에 탈출한다.
            if (pair < 1) {
                break;
            }
            round++;
            pair--;
        }

        return round;
    }

    private void matchCard(int card) {

        // (8) 코인이 1개 이상 있고, 가지고 있는 카드와 페어가 되면 해당 카드를 구매한다.
        if (myCoin > 0 && myCards.contains(n + 1 - card)) {
            myCoin--;
            pair++;
            return;
        }

        // (9) 이외에는 카드를 넘긴다.
        tempCards.add(card); // (9)
    }
}
