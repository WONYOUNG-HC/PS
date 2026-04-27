#include <iostream>
#include <string>

using namespace std;

int main() {
    string s; getline(cin, s);

    char arr[5] = {'U', 'C', 'P', 'C', '\0'};
    int cnt = 0;

    for (char c : s) {
        if (c == arr[cnt])
            cnt++;
    }

    cout << (cnt == 4 ? "I love UCPC" : "I hate UCPC");
}