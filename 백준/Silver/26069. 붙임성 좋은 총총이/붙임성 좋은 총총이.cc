#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    set<string> s = {"ChongChong"};
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if (s.find(a) != s.end() || s.find(b) != s.end())
            s.insert(a), s.insert(b);
    }

    cout << s.size();
}