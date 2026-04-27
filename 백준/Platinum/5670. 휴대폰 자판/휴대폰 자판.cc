#include <iostream>
#include <algorithm>

using namespace std;

int n;
string arr[100010];

struct Node {
    Node *child[26];
    int next;

    Node() {
        next = 0;
        fill_n(child, 26, nullptr);
    }

    void insert(string &s, int idx) {
        next++;

        if (s.length() == idx)
            return;

        if (!child[s[idx] - 'a']) {
            child[s[idx] - 'a'] = new Node;
        }

        child[s[idx] - 'a']->insert(s, idx + 1);
    }

    int search(string &s, int idx, int diff) {
        if (s.length() == idx)
            return idx - diff;

        if (child[s[idx] - 'a']->next == 1)
            return idx + 1 - diff;

        if (idx != 0 && next == child[s[idx] - 'a']->next)
            diff++;

        return child[s[idx] - 'a']->search(s, idx + 1, diff);
    }

    ~Node() {
        for (int i = 0; i < 26; i++)
            if (child[i])
                delete child[i];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        Node head;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            head.insert(arr[i], 0);
        }

        int tot = 0;
        for (int i = 0; i < n; i++) {
            tot += head.search(arr[i], 0, 0);
        }

        cout << fixed;
        cout.precision(2);
        cout << (double)tot / n << '\n';
    }
}