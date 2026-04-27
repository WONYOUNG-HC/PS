#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> s;
    int input;
    for (int i=0; i<n; i++) {
        cin >> input;
        s.insert(input);
    }

    for (int i : s)
        cout << i << ' ';
}