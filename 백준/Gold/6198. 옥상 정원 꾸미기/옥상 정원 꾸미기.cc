#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long Rooftop(vector<int>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin >> v[i];

    cout << Rooftop(v);
}

long long Rooftop(vector<int>& v) {
    stack<int> s;
    long long ans = 0;
    for (int i : v) {
        while (!(s.empty() || s.top() > i))
            s.pop();
        s.push(i);

        ans += (long long)s.size() - 1;
    }

    return ans;
}