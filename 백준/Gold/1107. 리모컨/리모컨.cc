#include <iostream>

using namespace std;

int IntSize(int num) {
    int ret = 0;

    if (!num) ret = 1;
    while (num) {
        num /= 10;
        ret++;
    }

    return ret;
}

bool Check(int target, const int broken[], int n) {
    int num;
    if (!target) {
        for (int i=0; i<n; i++) {
            if (!broken[i])
                return false;
        }
    }
    while (target) {
        num = target % 10;
        for (int i=0; i<n; i++) {
            if (num == broken[i])
                return false;
        }
        target /= 10;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int target;
    cin >> target;

    int n;
    cin >> n;
    int broken[n];
    for (int i=0; i<n; i++)
        cin >> broken[i];

    int initCnt = abs(target - 100);
    int targetUp = target, cntUp = 0, sizeUp = IntSize(target);
    int targetDown = target, cntDown = 0, sizeDown = sizeUp;
    while (cntUp + sizeUp < initCnt && cntDown + sizeDown < initCnt) {
        if (targetDown >= 0) {
            if (sizeDown != IntSize(targetDown)) sizeDown--;

            if (Check(targetDown, broken, n)) {
                cout << cntDown + sizeDown;
                return 0;
            }

            targetDown--; cntDown++;
        }

        if (sizeUp != IntSize(targetUp)) sizeUp++;

        if (Check(targetUp, broken, n)) {
            cout << cntUp + sizeUp;
            return 0;
        }

        targetUp++; cntUp++;
    }

    cout << initCnt;
}