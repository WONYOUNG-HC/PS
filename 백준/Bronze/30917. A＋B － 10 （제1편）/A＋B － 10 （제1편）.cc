#include <iostream>

using namespace std;

int main() {
    int resp;
    int a, b;

    for (int i = 1; i <= 9; i++) {
        cout << "? A " << i << endl;

        cin >> resp;

        if (resp == 1){
            a = i;

            break;
        }
    }

    for (int i = 1; i <= 9; i++) {
        cout << "? B " << i << endl;

        cin >> resp;

        if (resp == 1) {
            b = i;

            break;
        }
    }

    cout << "! " << a + b << endl;
}