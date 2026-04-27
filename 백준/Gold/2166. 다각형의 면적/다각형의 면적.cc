#include <iostream>

#define pdd pair<double, double>
#define X first
#define Y second

using namespace std;

int n;
pdd arr[10010];

double ccw(pdd a, pdd b, pdd c) {
    return (((b.X - a.X) * (c.Y - a.Y)) - ((b.Y - a.Y) * (c.X - a.X))) / 2;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &arr[i].X, &arr[i].Y);

    double ans = 0;
    for (int i = 1; i < n - 1; i++)
        ans += ccw(arr[0], arr[i], arr[i + 1]);

    printf("%.1lf", abs(ans));
}