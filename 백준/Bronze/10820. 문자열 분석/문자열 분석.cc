#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int arr[4] {0};

        for (char c : s) {
            if (isupper(c)) arr[1]++;
            else if (isalpha(c)) arr[0]++;
            else if (isdigit(c)) arr[2]++;
            else arr[3]++;
        }

        for (int x : arr)
            cout << x << ' ';
        cout << '\n';
    }
}