#include <iostream>
#include <cmath>

using namespace std;

int w, h, x, y, p;

bool isArea(int nx, int ny) {
    if (pow(nx - x, 2) + pow(ny - (y + h / 2), 2) <= pow(h / 2, 2))
        return true;

    if (pow(nx - (x + w), 2) + pow(ny - (y + h / 2), 2) <= pow(h / 2, 2))
        return true;

    if (x <= nx && nx <= x + w && y <= ny && ny <= y + h)
        return true;

    return false;
}

int main() {
    cin >> w >> h >> x >> y >> p;

    int ans = 0;
    for (int i = 0; i < p; i++) {
        int nx, ny;
        cin >> nx >> ny;
        isArea(nx, ny) && ans++;
    }

    cout << ans;
}