#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
int arr[10];
vector<int> v;
set<vector<int>> ans;

void f() {
    if (v.size() == m) {
        ans.insert(v);
        
        return;
    }

    for (int i = 0; i < n; i++) {
        v.push_back(arr[i]);

        f();

        v.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    f();

    for (auto a : ans) {
        for (int b : a) {
            cout << b << ' ';
        }

        cout << '\n';
    }
}