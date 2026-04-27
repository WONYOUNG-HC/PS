#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int c = getchar() - '0';
    while (c != '\n' - '0') {
        int k = 4;
        while (k > 0) {
            v.push_back(c / k);
            c %= k, k /= 2;
        }

        c = getchar() - '0';
    }

    int i = 0;
    while (i < v.size() && v[i] == 0) i++;

    if (i == v.size()) cout << 0;

    for (; i < v.size(); i++)
        cout << v[i];
}