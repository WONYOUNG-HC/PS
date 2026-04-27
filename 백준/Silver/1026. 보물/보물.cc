#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    multiset<int> a;
    multiset<int> b;

    int input;
    for (int i=0; i<n; i++) {
        cin >> input;
        a.insert(input);
    }
    for (int i=0; i<n; i++) {
        cin >> input;
        b.insert(input);
    }

    int ans = 0;
    auto iter = a.begin();
    auto riter = b.rbegin();
    for (int i=0; i<n; i++) {
        ans += (*iter) * (*riter);
        iter++; riter++;
    }

    cout << ans;
}