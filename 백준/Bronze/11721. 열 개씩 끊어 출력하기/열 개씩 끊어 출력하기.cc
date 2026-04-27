#include <iostream>

using namespace std;

int main() {
    char c = getchar();
    while (c != '\n') {
        for (int i = 0; i < 10 && c != '\n'; i++) {
            cout << c;
            c = getchar();
        }
        cout << '\n';
    }
}