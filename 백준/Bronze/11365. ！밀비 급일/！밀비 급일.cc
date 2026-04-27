#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  while (true) {
    string str;
    getline(cin, str);

    if (str == "END") {
      break;
    }

    reverse(str.begin(), str.end());
    cout << str << '\n';
  }
}