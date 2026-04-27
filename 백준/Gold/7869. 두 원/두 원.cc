#include <iostream>
#include <cmath>

using namespace std;
using ld = long double;

int main() {
    ld x1, y1, r1, x2, y2, r2;

    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    
    ld d = hypot(x1 - x2, y1 - y2);

    cout << fixed;
    cout.precision(3);

    if (r1 + r2 <= d) {
        cout << 0.0;
    } else if (abs(r1 - r2) >= d) {
        cout << pow(min(r1, r2), 2) * M_PI;
    } else {
        ld theta1 = 2 * acos((pow(d, 2) - pow(r2, 2) + pow(r1, 2)) / (2 * d * r1));
        ld theta2 = 2 * acos((pow(d, 2) - pow(r1, 2) + pow(r2, 2)) / (2 * d * r2));

        ld w1 = (pow(r1, 2) * M_PI * (theta1 / (2 * M_PI))) - ((pow(r1, 2) * sin(theta1)) / 2);
        ld w2 = (pow(r2, 2) * M_PI * (theta2 / (2 * M_PI))) - ((pow(r2, 2) * sin(theta2)) / 2);

        cout << w1 + w2;
    }
}