#include <bits/stdc++.h>
using namespace std;

deque<int> gears[4];

const int RIGHT = 2;
const int LEFT = 6;

const int FIRST = 0;
const int SECOND = 1;
const int THIRD = 2;
const int FOURTH = 3;

const int CLOCKWISE = 1;
const int REVERSE = -1;

void rotate(int idx, int dir) {
    deque<int> &gear = gears[idx];

    if (dir == CLOCKWISE) {
        int back = gear.back();
        gear.pop_back();
        gear.push_front(back);
    } else {
        int front = gear.front();
        gear.pop_front();
        gear.push_back(front);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            gears[i].push_back(c - '0');
        }
    }

    int k;
    cin >> k;

    while(k--) {
        bool diff12 = gears[FIRST][RIGHT] != gears[SECOND][LEFT];
        bool diff23 = gears[SECOND][RIGHT] != gears[THIRD][LEFT];
        bool diff34 = gears[THIRD][RIGHT] != gears[FOURTH][LEFT];

        int idx, dir;
        cin >> idx >> dir;

        if (idx == 1) {
            rotate(FIRST, dir);

            if (diff12) {
                rotate(SECOND, -dir);

                if (diff23) {
                    rotate(THIRD, dir);

                    if (diff34) {
                        rotate(FOURTH, -dir);
                    }
                }
            }
        } else if (idx == 2) {
            rotate(SECOND, dir);

            if (diff12) {
                rotate(FIRST, -dir);
            }
            
            if (diff23) {
                rotate(THIRD, -dir);

                if (diff34) {
                    rotate(FOURTH, dir);
                }
            }
        } else if (idx == 3) {
            rotate(THIRD, dir);

            if (diff34) {
                rotate(FOURTH, -dir);
            }

            if (diff23) {
                rotate(SECOND, -dir);

                if (diff12) {
                    rotate(FIRST, dir);
                }
            }
        } else {
            rotate(FOURTH, dir);

            if (diff34) {
                rotate(THIRD, -dir);

                if (diff23) {
                    rotate(SECOND, dir);

                    if (diff12) {
                        rotate(FIRST, -dir);
                    }
                }
            }
        }
    }

    int ans;
    ans += gears[FIRST][0];
    ans += 2 * gears[SECOND][0];
    ans += 4 * gears[THIRD][0];
    ans += 8 * gears[FOURTH][0];

    cout << ans;
}