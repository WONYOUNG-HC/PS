#include <iostream>

using namespace std;

int main() {
    double d;
    char c = getchar();

    if (c == 'A') d = 4;
    else if (c == 'B') d = 3;
    else if (c == 'C') d = 2;
    else if (c == 'D') d = 1;
    else d = 0;

    c = getchar();

    if (c == '+') d += 0.3;
    else if (c == '-') d -= 0.3;

    printf("%.1lf", d);
}