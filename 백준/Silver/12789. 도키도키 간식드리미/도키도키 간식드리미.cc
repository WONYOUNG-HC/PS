#include <iostream>
#include <stack>

using namespace std;

int n;
int arr[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n ; i++)
        cin >> arr[i];

    stack<int> s;
    int k = 1, i = 0;
    
    while (k < n) {
        if (arr[i] == k) {
            i += 1;
            k += 1;
        }
        else if (!s.empty() && s.top() == k) {
            s.pop();
            k += 1;
        }
        else if (s.empty() || s.top() > arr[i]) {
            s.push(arr[i++]);
        }
        else {
            cout << "Sad";
            return 0;
        }
    }

    cout << "Nice";
}