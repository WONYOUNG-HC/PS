#include <iostream>

using namespace std;

int n, k;
int durability[210];
bool robot[210];

int next(int x, int step = 1) {
    return ((x - 1 + step + (2 * n)) % (2 * n)) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= 2 * n; i++) {
        cin >> durability[i];
    }

    //
    //
    //

    int current = 1;
    int answer = 0;

    while (k > 0) {
        // move belt
        current = next(current, -1);

        int end = next(current, n - 1);

        if (robot[end]) {
            robot[end] = false;
        }

        // move robot
        for (int i = end; i != current; i = next(i, -1)) {
            if (!robot[next(i, -1)]) {
                continue;
            }

            if (!robot[i] && durability[i] > 0) {
                swap(robot[next(i, -1)], robot[i]);
                durability[i] -= 1;

                if (durability[i] == 0) {
                    k -= 1;
                }
            }

            if (i == end) {
                robot[i] = false;
            }
        }

        if (robot[end]) {
            robot[end] = false;
        }

        // place a robot
        if (durability[current] > 0) {
            robot[current] = true;
            durability[current] -= 1;

            if (durability[current] == 0) {
                k -= 1;
            }
        }

        answer += 1;
    }

    cout << answer;
}