#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct Element {
    int prev;
    char op;
};

Element route[10000];

void Bfs(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        fill(route, route+10000, Element{0, '\0'});
        int a, b;
        cin >> a >> b;
        Bfs(a, b);
    }
}

int Double(int n) {
    return (n*2) % 10000;
}

int Sub(int n) {
    if (n == 0)
        return 9999;
    return n-1;
}

int Left(int n) {
    n *= 10;

    int d = n / 10000;
    int m = n % 10000;

    return m + d;
}

int Right(int n) {
    int d = n / 10;
    int m = n % 10;

    return (m*1000) + d;
}

void QueuePush(int a, int n, queue<int>& q, char op) {
    if (route[n].op != '\0')
        return;

    route[n].prev = a;
    route[n].op = op;
    q.push(n);
}

void Bfs(int a, int b) {
    queue<int> q;
    q.push(a);
    route[a].op = '_';

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        if (n == b) {
            stack<char> s;
            Element e = route[n];
            while (e.op != '_') {
                s.push(e.op);
                e = route[e.prev];
            }

            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
            cout << '\n';

            return;
        }

        QueuePush(n, Double(n), q, 'D');
        QueuePush(n, Sub(n), q, 'S');
        QueuePush(n, Left(n), q, 'L');
        QueuePush(n, Right(n), q, 'R');
    }
}