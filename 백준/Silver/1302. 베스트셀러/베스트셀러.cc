#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, int> m;
    pair<map<string, int>::iterator, bool> pr;
    string str;
    for (int i=0; i<n; i++) {
        cin >> str;
        pr = m.insert({str, 1});

        if (!pr.second)
            m[str]++;
    }

    int cnt = 0;
    for (auto& i : m) {
        if (i.second > cnt) {
            cnt = i.second;
            str = i.first;
        }
    }

    cout << str;
}