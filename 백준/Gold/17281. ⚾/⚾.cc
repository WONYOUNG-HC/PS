#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[60][10];
int players[10] = {1, 2, 3, 4, 5, 6, 7, 8};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    int answer = 0;

    do {
        int score = 0;
        int entry[10];
        
        for (int i = 0; i < 9; i++) {
            if (i < 3) {
                entry[i] = players[i];
            } else if (i > 3) {
                entry[i] = players[i - 1];
            }
        }

        entry[3] = 0;

        //
        //
        //

        int entry_index = 0;

        for (int i = 0; i < n; i++) {
            int out_count = 0;
            int base[5] = {0, };

            while (out_count < 3) {
                int result = arr[i][entry[entry_index]];

                if (result == 0) {
                    out_count += 1;
                } else {
                    for (int j = 3; j > 0; j--) {
                        base[min(4, j + result)] += base[j];
                        base[j] = 0;
                    }
    
                    base[result] += 1; 
                }

                entry_index = (entry_index + 1) % 9;
            }

            score += base[4];
        }

        answer = max(answer, score);
    } while (next_permutation(players, players + 8));

    cout << answer;
}