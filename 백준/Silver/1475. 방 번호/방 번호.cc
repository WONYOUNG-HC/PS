#include <iostream>
#include <string>

using namespace std;

string str;
int numbers[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;

    int answer = 0;

    for (int i = 0; i < str.size(); i++) {
        int num = str[i] - '0';

        if (num == 9) {
            num = 6;
        }

        if (numbers[num] == 0) {
            for (int j = 0; j <= 8; j++) {
                numbers[j] += 1;
            }

            numbers[6] += 1;

            answer += 1;
        }

        numbers[num] -= 1;
    }

    cout << answer;
}