#include <iostream>

int main() {
    int h, m;
    std::cin >> h >> m;

    int ans = h * 60 + m - 45;
    ans < 0 && (ans += 60 * 24);
    std::cout << ans / 60 << ' ' << ans % 60;
}