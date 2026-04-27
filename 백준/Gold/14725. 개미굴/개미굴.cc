#include <iostream>
#include <map>

using namespace std;

int n, k;
string arr[20];

struct Node {
    map<string, Node *> child;

    void insert(int idx) {
        if (idx == k)
            return;

        if (child.find(arr[idx]) == child.end()) {
            child[arr[idx]] = new Node;
        }

        child[arr[idx]]->insert(idx + 1);
    }

    void print(int depth) {
        if (child.empty())
            return;

        for (auto it : child) {
            for (int i = 0; i < depth; i++)
                cout << "--";
            
            cout << it.first << '\n';
            it.second->print(depth + 1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    Node *head = new Node;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> arr[j];
        }

        head->insert(0);
    }

    head->print(0);
}