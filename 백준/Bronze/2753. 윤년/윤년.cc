#include <iostream>

int main() {
    int n; std::cin >> n;
    std::cout << ((!(n % 4) && (n % 100)) || !(n % 400));
}