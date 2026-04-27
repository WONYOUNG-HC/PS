#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <cmath>

using namespace std;

set<int> st;

int time_num(vector<int> v) {
    int ret = 9999;

    for (int i = 0; i < 4; i++) {
        int num = 0;
        
        for (int j = 0; j < 4; j++) {
            num += v[j] * pow(10, 3 - j);
        }

        ret = min(ret, num);

        v.push_back(v[0]);
        v.erase(v.begin());    
    }

    return ret;
}

void f(vector<int> v) {
    if (v.size() == 4) {
        st.insert(time_num(v));

        return;
    }

    for (int i = 1; i < 10; i++) {
        v.push_back(i);

        f(v);

        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v;

    f(v);

    for (int i = 0; i < 4; i++) {
        int a;

        cin >> a;

        v.push_back(a);
    }

    int ans = distance(st.begin(), st.find(time_num(v))) + 1;

    cout << ans;
}