#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> s;
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        s.insert(str);
    }

    int len = (int)(*s.begin()).size();
    for (int i=1; i<len; i++) {
        set<string> tmp;
        for (const auto& iter : s) {
            string str;
            str.assign(iter.begin()+1, iter.end());
            tmp.insert(str);
        }

        if (s.size() != tmp.size()) {
            cout << (*s.begin()).size();
            return 0;
        }

        s = tmp;
    }

    cout << 1;
}