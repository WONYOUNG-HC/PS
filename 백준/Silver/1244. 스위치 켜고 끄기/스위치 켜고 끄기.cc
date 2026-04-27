#include <iostream>
#include <vector>

using namespace std;

int n;
vector<bool> switches;

void Boy(int num);
void Girl(int num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    switches.resize(n+1, false);
    for (int i=1; i<=n; i++) {
        int cond; cin >> cond;
        if (cond == 1)
            switches[i] = true;
    }

    int m;
    cin >> m;

    for (int i=0; i<m; i++) {
        int gender, num;
        cin >> gender >> num;

        if (gender == 1)
            Boy(num);
        else
            Girl(num);
    }

    for (int i=1; i<=n; i++) {
        cout << switches[i] << ' ';

        if (i % 20 == 0)
            cout << '\n';
    }
}

void Boy(int num) {
    int k = num;

    while(k <= n) {
        switches[k] = !switches[k];
        k += num;
    }
}

void Girl(int num) {
    int i = num - 1;
    int j = num + 1;

    switches[num] = !switches[num];
    while (0 < i && j <= n) {
        if (switches[i] != switches[j])
            return;

        switches[i] = !switches[i];
        switches[j] = !switches[j];
        i--; j++;
    }
}