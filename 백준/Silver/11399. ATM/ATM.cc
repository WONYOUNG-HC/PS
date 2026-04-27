#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> line(n);
    int time;
    for (int i=0; i<n; i++) {
        cin >> time;
        line[i] = time;
    }

    sort(line.begin(), line.end());

    int sum = 0;
    for (auto iter = line.begin()+1; iter <= line.end(); iter++)
        sum += accumulate(line.begin(), iter, 0);

    cout << sum;
}