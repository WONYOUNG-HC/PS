#include <iostream>

int a[26], c;

int main() {
    while ((c = getchar()) != '\n') a[c - 'a']++;
    for (int x : a) std::cout << x <<' ';
}