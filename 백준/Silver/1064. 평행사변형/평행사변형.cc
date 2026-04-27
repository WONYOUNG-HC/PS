#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using pdd = pair<double, double>;

int main() {
    pdd arr[3];
    for (pdd &x : arr)
        cin >> x.first >> x.second;
    
    double dist[3];
    for (int i = 0; i < 2; i++)
        for (int j = i + 1; j < 3; j++)
            dist[i + j - 1] = sqrt(pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2));
    
    sort(dist, dist + 3);
    double ans = 2 * (dist[1] + dist[2]) - 2 * (dist[0] + dist[1]);
    !((arr[0].first - arr[1].first) * (arr[1].second - arr[2].second) - (arr[0].second - arr[1].second) * (arr[1].first - arr[2].first)) && (ans = -1);
    
    cout << fixed;
    cout.precision(10);
    cout << ans;
}