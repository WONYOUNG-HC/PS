#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str; str += '\0';

    vector<char> s;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == 'P') {
            s.push_back('P');
        }
        else if (str[i] == 'A' && s.size() >= 2 && *s.rbegin() == 'P' && *(++s.rbegin()) == 'P' && str[++i] == 'P')
            s.pop_back();
        else {
            s.push_back('A');
            break;
        }
        i++;
    }

    cout << (s.size() == 1 && s[0] == 'P' ? "PPAP" : "NP");
}