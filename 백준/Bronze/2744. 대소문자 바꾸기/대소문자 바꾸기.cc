#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char c;
    while ((c = getchar()) != '\n')
        cout << (isupper(c) ? (char)tolower(c) : (char)toupper(c));
}