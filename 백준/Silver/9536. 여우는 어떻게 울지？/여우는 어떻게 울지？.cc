#include <iostream>
#include <list>

using namespace std;

list<string> split(string& s) {
    list<string> ret;

    int idx = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == ' ') {
            ret.push_back(s.substr(idx, i - idx));
            idx = i + 1;
        }
    }
    ret.push_back(s.substr(idx, s.length() - idx));

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    cin.ignore();

    while (tc--) {
        string str;
        getline(cin, str);

        list<string> lt = split(str);
        while (true) {
            string q;
            getline(cin, q);

            if (q == "what does the fox say?")
                break;

            lt.remove(split(q).back());
        }

        for (string& s : lt)
            cout << s << ' ';
        cout << '\n';
    }
}