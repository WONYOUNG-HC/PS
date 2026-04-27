#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll x, y, w, s;
vector<ll> ans;

int main() {
    cin >> x >> y >> w >> s;

    ans.push_back((x + y) * w);
    ans.push_back(min(x, y) * s + abs(x - y) * w);
    ans.push_back((max(x, y) - abs(x - y) % 2) * s + (abs(x - y) % 2 ? w : 0));

    cout << *min_element(ans.begin(), ans.end());
}