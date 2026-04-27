#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while (tc--) {
        multiset<int> ms;
        int n;
        cin >> n;

        char order;
        int num;
        for (int i=0; i<n; i++) {
            cin >> order >> num;

            if (order == 'I')
                ms.insert(num);
            else if (num == 1) {
                if (!ms.empty()) ms.erase(--ms.end());
            }
            else if (num == -1) {
                if (!ms.empty()) ms.erase(ms.begin());
            }
        }

        ms.empty() ? cout << "EMPTY \n" : cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
    }
}