#include <iostream>
#include <string>

using namespace std;

int n, f[1000010];
string str;

void failure() {
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && str[i] != str[j])
            j = f[j - 1];
        
        if (str[i] == str[j])
            f[i] = ++j;
    }
}


int main() {
    cin >> n >> str;
    
    failure();
    cout << n - f[n - 1];
}