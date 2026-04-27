#include <iostream>

using namespace std;

int arr[128][128];
int cnt_0, cnt_1;

void PaperCut(int y, int x, int size);
bool IsColorPaper(int y, int x, int size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    PaperCut(0, 0, n);

    cout << cnt_0 << '\n' << cnt_1;
}

void PaperCut(int y, int x, int size) {
    if (IsColorPaper(y, x, size))
        return;

    size /= 2;
    PaperCut(y, x, size);
    PaperCut(y, x+size, size);
    PaperCut(y+size, x, size);
    PaperCut(y+size, x+size, size);
}

bool IsColorPaper(int y, int x, int size) {
    if (size == 1) {
        arr[y][x] ? cnt_1++ : cnt_0++;
        return true;
    }

    int color = arr[y][x];
    for (int i=y; i<y+size; i++) {
        for (int j=x; j<x+size; j++) {
            if (color != arr[i][j]) return false;
        }
    }
    color ? cnt_1++ : cnt_0++;
    return true;
}