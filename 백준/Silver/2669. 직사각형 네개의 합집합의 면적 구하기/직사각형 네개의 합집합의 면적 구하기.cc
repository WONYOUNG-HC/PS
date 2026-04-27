#include <iostream>
#include <set>

using namespace std;
using pii = pair<int, int>;

set<pii> s;

int main() {
    for (int i = 0; i < 4; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                s.insert({x, y});
            }
        }
    }

    cout << s.size();
}