#include <iostream>
#include <string>

using namespace std;

bool isCroatia(string& lexeme) {
    if (lexeme == "c=")
        return true;
    if (lexeme == "c-")
        return true;
    if (lexeme == "dz=")
        return true;
    if (lexeme == "d-")
        return true;
    if (lexeme == "lj")
        return true;
    if (lexeme == "nj")
        return true;
    if (lexeme == "s=")
        return true;
    if (lexeme == "z=")
        return true;

    return false;
}

int main() {
    string s; cin >> s;

    string lexeme;
    int ans = 0;

    for (char c : s) {
        lexeme += c;

        if (isCroatia(lexeme)) {
            ans += 1;
            lexeme.clear();
        }
        else if (lexeme.size() == 2 && lexeme != "dz") {
            ans += 1;
            lexeme = lexeme.substr(1);
        }
        else if (lexeme.size() == 3) {
            ans += 2;
            lexeme = lexeme.substr(2, 1);
        }
    }

    if (isCroatia(lexeme))
        ans += 1;
    else
        ans += lexeme.size();

    cout << ans;
}