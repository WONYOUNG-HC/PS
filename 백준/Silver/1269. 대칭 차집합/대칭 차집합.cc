#include <iostream>
#include <set>

using namespace std;

void Difference(multiset<int>& s1, multiset<int>& s2, set<int>& s3) {
    multiset<int>::iterator iter1, iter2;
    iter1 = s1.begin();
    iter2 = s2.begin();

    while (iter1 != s1.end()) {
        if (iter2 == s2.end() || *iter1 < *iter2) {
            s3.insert(*iter1);
            iter1++;
        }
        else if (*iter1 > *iter2) {
            iter2++;
        }
        else {
            iter1++;
            iter2++;
        }
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    int n;
    multiset<int> s1;
    for (int i=0; i<a; i++) {
        cin >> n;
        s1.insert(n);
    }

    multiset<int> s2;
    for (int i=0; i<b; i++) {
        cin >> n;
        s2.insert(n);
    }

    set<int> s3;
    Difference(s1, s2, s3);
    Difference(s2, s1, s3);

    cout << s3.size();
}