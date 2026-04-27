#include <iostream>
#include <queue>

using namespace std;

int n;
bool arr[1010], vis[1010];

int main() {
    cin >> n;

    queue<int> q;
    q.push(1);
    arr[1] = true, vis[1] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == n) {
            cout << (arr[n] ? "SK" : "CY");
            break;
        }

        if (!vis[x + 1]) {
            arr[x + 1] = !arr[x];
            vis[x + 1] = true;
            q.push(x + 1);
        }
        if (!vis[x + 3]) {
            arr[x + 3] = !arr[x];
            vis[x + 3] = true;
            q.push(x + 3);
        }
    }
}