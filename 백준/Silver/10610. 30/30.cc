#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    string num;
    cin >> num;

    bool flag = false;
    int sum = 0;
    for (char c : num) {
        if (c == '0') {
            flag = true;
        }
        sum += atoi(&c);
    }

    sort(num.begin(), num.end(), greater<>());
    if (!flag || sum % 3 != 0)
        cout << -1;
    else
        cout << num;
}