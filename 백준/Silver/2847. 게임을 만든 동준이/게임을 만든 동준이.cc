#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> score(n);
    for (int i=0; i<n; i++)
        cin >> score[i];

    int cnt = 0;
    for (int i=n-2; i>=0; i--) {
        if (score[i] >= score[i+1]) {
            cnt += score[i] - score[i+1] + 1;
            score[i] = score[i+1] - 1;
        }
    }

    cout << cnt;
}