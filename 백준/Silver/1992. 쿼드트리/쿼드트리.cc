#include <iostream>

using namespace std;

char arr[64][65];

void QuadTree(int y, int x, int n);
bool Pred(int y, int x, int n);

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++)
        cin >> arr[i];

    QuadTree(0, 0, n);
}

void QuadTree(int y, int x, int n) {
    if (Pred(y, x, n)) {
        cout << arr[y][x];
        return;
    }

    n /= 2;
    cout << '(';

    QuadTree(y, x, n);
    QuadTree(y, x+n, n);
    QuadTree(y+n, x, n);
    QuadTree(y+n, x+n, n);

    cout << ')';
}

bool Pred(int y, int x, int n) {
    char color = arr[y][x];
    for (int i=y; i<y+n; i++)
        for (int j=x; j<x+n; j++)
            if (arr[i][j] != color) return false;

    return true;
}