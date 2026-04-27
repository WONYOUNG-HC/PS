#include <iostream>
#include <map>

using namespace std;

int n, k;
string arr[500010];
map<string, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        string num; cin >> num;

        arr[i] = num;
        if (m.find(num) == m.end())
            m[num] = 0;
        else
            m[num]++;
    }

    int cnt = 0;
    for (int i = 0; i < n && cnt < k; i++) {
        string num = arr[i];

        if (m[num] > 0) {
            m[num]--;
        }
        else {
            cout << num << '\n';
            cnt++;
        }
    }
}