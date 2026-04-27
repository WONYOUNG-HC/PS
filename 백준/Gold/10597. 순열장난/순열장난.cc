#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int n;
string str;
bool vis[55];
vector<int> v;

void f(int i) {
    if (i == str.length()) {
        for (int x : v)
            cout << x << ' ';   
        exit(0);
    }

    string s1 = str.substr(i, 1);
    int x1 = stoi(s1);
    if (x1 <= n && !vis[x1]) {
        vis[x1] = true;
        v.push_back(x1);
        f(i + 1);
        vis[x1] = false;
        v.pop_back();
    }

    if (i + 1 == str.length())
        return;

    string s2 = str.substr(i, 2);
    int x2 = stoi(s2);
    if (x2 <= n && !vis[x2]) {
        vis[x2] = true;
        v.push_back(x2);
        f(i + 2);
        vis[x2] = false;
        v.pop_back();
    }
}

int main() {
    cin >> str;

    if (str.length() < 10)
        n = str.length();
    else
        n = 9 + ((str.length() - 9) / 2);

    f(0);
}