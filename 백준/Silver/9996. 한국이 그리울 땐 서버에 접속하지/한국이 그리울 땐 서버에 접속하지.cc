#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    string str; cin >> str;

    string s1 = str.substr(0, str.find('*'));
    string s2 = str.substr(str.find('*') + 1);

    while (n--) {
        string s; cin >> s;

        if (s.size() >= str.size() - 1 && (s1 == s.substr(0, s1.size())) && (s2 == s.substr(s.size() - s2.size())))
            cout << "DA \n";
        else
            cout << "NE \n";
    }
}