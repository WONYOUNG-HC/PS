#include <iostream>

using namespace std;

int n;
double arr[1010];

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n; 
        double sum = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        double avg = sum / n;
        double cnt = 0;
        for (int i = 0; i < n; i++)
            arr[i] > avg && cnt++;

        cout << fixed;
        cout.precision(4);
        cout << (cnt / n) * 100 << "%\n";
    }
}