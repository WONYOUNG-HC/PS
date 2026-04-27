#include <iostream>

enum {LEFT_CHILD, RIGHT_CHILD};

using namespace std;

int tree[10000001][2];

void PostOrder(int num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int input, num, root;
    cin >> input;
    if (cin.fail()) return 0;
    root = num = input;

    while (true) {
        cin >> input;
        if (cin.fail()) break;

        if (input < num)
            tree[num][LEFT_CHILD] = input;
        else {
            int prev = -1;
            num = root;
            while (num != prev) {
                prev = num;
                if (input < num && tree[num][LEFT_CHILD])
                    num = tree[num][LEFT_CHILD];
                else if (input > num && tree[num][RIGHT_CHILD])
                    num = tree[num][RIGHT_CHILD];
            }

            if (input < num)
                tree[num][LEFT_CHILD] = input;
            else
                tree[num][RIGHT_CHILD] = input;
        }

        num = input;
    }

    PostOrder(root);
}

void PostOrder(int num) {
    if (tree[num][LEFT_CHILD]) PostOrder(tree[num][LEFT_CHILD]);
    if (tree[num][RIGHT_CHILD]) PostOrder(tree[num][RIGHT_CHILD]);
    cout << num << '\n';
}