#include <iostream>
#include <string>

using namespace std;

bool set[20];
int x;

void Add();
void Remove();
void Check();
void Toggle();
void All();
void Empty();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string order;

    int n;
    cin >> n;
    while (n--) {
        cin >> order;

        if (order == "add") {
            cin >> x;
            Add();
        }
        else if (order == "remove") {
            cin >> x;
            Remove();
        }
        else if (order == "check") {
            cin >> x;
            Check();
        }
        else if (order == "toggle") {
            cin >> x;
            Toggle();
        }
        else if (order == "all") All();
        else if (order == "empty") Empty();
    }
}

void Add() {
    set[x-1] = true;
}

void Remove() {
    set[x-1] = false;
}

void Check() {
    if (set[x-1]) cout << "1 \n";
    else cout << "0 \n";
}

void Toggle() {
    if (set[x-1]) set[x-1] = false;
    else set[x-1] = true;
}

void All() {
    for (bool & i : set)
        i = true;
}

void Empty() {
    for (bool & i : set)
        i = false;
}
