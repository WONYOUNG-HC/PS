#include <iostream>

using namespace std;
using ll = long long;

int n;
ll ans;
ll arr[100010];

ll area(int start, int end, ll height) {
    return (end - start + 1) * height;
}

void f(int start, int end) {
    if (start == end) {
        ans = max(ans, arr[start]);

        return;
    }
    
    //
    //
    //

    int mid = (start + end) / 2;
    int left_start = start;
    int left_end = mid;
    int right_start = mid + 1;
    int right_end = end;

    f(left_start, left_end);
    f(right_start, right_end);

    //
    //
    //

    int left_index = left_end;
    int right_index = right_start;

    ll height = min(arr[left_index], arr[right_index]);
    ans = max(ans, area(left_index, right_index, height));

    while (left_index > start || right_index < end) {
        ll new_left_height = min(height, arr[left_index]);
        ll new_right_height = min(height, arr[right_index]);

        if (left_index > start) {
            new_left_height = arr[left_index - 1];
        }

        if (right_index < end) {
            new_right_height = arr[right_index + 1];
        }

        if (left_index == start) {
            right_index += 1;
            height = min(height, new_right_height);
        } else if (right_index == end) {
            left_index -= 1;
            height = min(height, new_left_height);
        } else if (new_left_height > new_right_height) {
            left_index -= 1;
            height = min(height, new_left_height);
        } else if (new_right_height > new_left_height) {
            right_index += 1;
            height = min(height, new_right_height);
        } else {
            left_index -= 1;
            right_index += 1;
            height = min(height, min(new_left_height, new_right_height));
        }

        ans = max(ans, area(left_index, right_index, height));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ans = 0;

        f(0, n - 1);

        cout << ans << '\n';
    }
}