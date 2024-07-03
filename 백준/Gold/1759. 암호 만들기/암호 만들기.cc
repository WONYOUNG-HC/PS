#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char arr[20];
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
string s;

int is_vowel(char x) {
    for (int i = 0; i < 5; i++) 
        if (vowel[i] == x)
            return 1;

    return 0;
}

void f(int i) {
    if (s.length() == l) {
        int cnt = 0;
        for (char x : s) {
            cnt += is_vowel(x);
        }

        if (cnt >= 1 && l - cnt >= 2) {
            cout << s << '\n';
        }

        return;
    }

    for (int j = i; j < c; j++) {
        s.push_back(arr[j]);
        f(j + 1);
        s.pop_back();
    }
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++)
        cin >> arr[i];
    
    sort(arr, arr + c);

    f(0);
}