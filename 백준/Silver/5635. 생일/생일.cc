#include <iostream>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int day, month, year;
};

bool cmp(const Person& left, const Person& right) {
    if (left.year != right.year)
        return left.year < right.year;

    if (left.month != right.month)
        return left.month < right.month;

    return left.day < right.day;
}

int n;
Person arr[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].name >> arr[i].day >> arr[i].month >> arr[i].year;

    sort(arr, arr + n, cmp);

    cout << arr[n - 1].name << '\n' << arr[0].name;
}