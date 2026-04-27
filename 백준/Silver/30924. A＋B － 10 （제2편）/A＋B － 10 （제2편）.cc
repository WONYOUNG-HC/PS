#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int query_a[10010];
int query_b[10010];

int main() {
    srand(time(0));

    for (int i = 1; i <= 10000; i++) {
        query_a[i] = query_b[i] = i;
    }

    random_shuffle(query_a + 1, query_a + 10001);
    random_shuffle(query_b + 1, query_b + 10001);

    int resp;
    int a = 0;
    int b = 0;

    for (int i = 1; i <= 10000; i++) {
        int query = query_a[i];

        cout << "? A " << query << endl;

        cin >> resp;

        if (resp == 1) {
            a = query;

            break;
        }
    }

    for (int i = 1; i <= 10000; i++) {
        int query = query_b[i];

        cout << "? B " << query << endl;

        cin >> resp;

        if (resp == 1) {
            b = query;

            break;
        }
    }

    cout << "! " << a + b << endl;
}