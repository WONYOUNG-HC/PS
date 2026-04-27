#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int dvd[100005];

bool Decision(int n, int m, int mid) {
	int cnt = 0;
	int time = 0;
	
	for (int i = 0; i < n; i++) {
		if (dvd[i] > mid) {
			return false;
		}
		
		time += dvd[i];
		
		if (time > mid) {
			cnt++;
			time = dvd[i];
		}
		
		if (cnt > m) {
			return false;
		}
	}
	
	return cnt + 1 <= m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> dvd[i];
	}
	
	int left = *max_element(dvd, dvd + n);
	int right = accumulate(dvd, dvd + n, 0);
	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (Decision(n, m, mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	
    cout << left;
}