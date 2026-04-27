#include <iostream>
#include <algorithm>

using namespace std;

int s, p;
string str;
int arr[128], cnt[128];

bool chk() {
    return arr['A'] <= cnt['A'] && arr['C'] <= cnt['C'] && arr['G'] <= cnt['G'] && arr['T'] <= cnt['T'];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> p;
    cin >> str;
    cin >> arr['A'] >> arr['C'] >> arr['G'] >> arr['T'];

    int ans = 0;
    int l = 1, r = p;
    for (int i = 0; i < p; i++)
        cnt[str[i]]++;
    chk() && ans++;

    while (r < s) {
        cnt[str[l - 1]]--, cnt[str[r]]++;
        chk() && ans++;
        l++, r++;
    }

    cout << ans;
}