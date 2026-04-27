#include <iostream>
#include <algorithm>
#include <cmath>

#define pdd pair<double, double>
#define X first
#define Y second

using namespace std;

const double RT = sqrt(2.0);
pdd arr[8], graph[8];
double dir[8][2] = {{0, 1}, {1 / RT, 1 / RT}, {1, 0}, {1 / RT, -1 / RT},
                    {0, -1}, {-1 / RT, -1 / RT}, {-1, 0}, {-1 / RT, 1 / RT}};

bool ccw(pdd& a, pdd& b, pdd& c) {
    return ((a.X - c.X) * (b.Y - c.Y)) - ((a.Y - c.Y) * (b.X - c.X)) > 0;
}

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr, arr + 8);

    int ans = 0;
    do {
        for (int i = 0; i < 8; i++)
            graph[i] = {arr[i].first * dir[i][0], arr[i].first * dir[i][1]};

        bool flag = true;
        for (int i = 0; i < 8; i++) {
            if (ccw(graph[i], graph[(i + 1) % 8], graph[(i + 2) % 8])) {
                flag = false;
                break;
            }
        }

        flag && ans++;

    } while (next_permutation(arr, arr + 8));

    cout << ans;
}