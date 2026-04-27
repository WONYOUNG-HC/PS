#include <iostream>

using namespace std;

int main() {
    int price; cin >> price;

    int coin[] = {500, 100, 50, 10, 5, 1};
    int money = 1000 - price, change = 0;
    for (int i = 0; i < 6; i++) {
        change += money / coin[i];
        money %= coin[i];
    }

    cout << change;
}