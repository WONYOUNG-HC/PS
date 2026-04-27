#include <iostream>
#include <algorithm>

using namespace std;

const int src = 0, dest = 39;

int arr[10];
int score[40];
int route[40];
int pri[40];
int ans;

void f(int sum, int cnt, int *stat) {
    if (cnt == 10) {
        ans = max(ans, sum);

        return;
    }

    for (int i = 0; i < 4; i++) {
        if (stat[i] == dest) {
            continue;
        }

        int pos = stat[i];
        
        pos = pri[pos] > 0 ? pri[pos] : route[pos];

        for (int j = 0; j < arr[cnt] - 1; j++) {
            if (pos == dest) {
                break;
            }

            pos = route[pos];
        }

        int idx = find(stat, stat + 4, pos) - stat;
        
        if (idx < 4 && stat[idx] != dest) {
            continue;
        }

        //
        //
        //

        swap(pos, stat[i]);

        f(sum + score[stat[i]], cnt + 1, stat);

        swap(pos, stat[i]);
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    //
    //
    //

    route[src] = 1;

    for (int i = 1; i <= 20; i++) {
        score[i] = i * 2;
        route[i] = i + 1;
    }

    route[20] = dest;

    pri[5] = 26;
    pri[10] = 32;
    pri[15] = 29;

    score[26] = 13;
    score[27] = 16;
    score[28] = 19;
    route[26] = 27;
    route[27] = 28;
    route[28] = 25;

    score[29] = 28;
    score[30] = 27;
    score[31] = 26;
    route[29] = 30;
    route[30] = 31;
    route[31] = 25;

    score[32] = 22;
    score[33] = 24;
    route[32] = 33;
    route[33] = 25;

    score[25] = 25;
    route[25] = 34;

    score[34] = 30;
    score[35] = 35;
    route[34] = 35;
    route[35] = 20;

    //
    //
    //
    
    int stat[4] = {src, src, src, src};

    f(0, 0, stat);

    cout << ans;
}