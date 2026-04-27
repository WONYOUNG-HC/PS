#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int cnt = 0;
	vector<bool> sieve(n + 1, true);
	for (int i = 2; i <= n; i++) {
		if (!sieve[i])
			continue;
	
		cnt++;
		
		if (cnt == k) {
			cout << i;
			return 0;
		}
		
		int j = i + i;
		while (j <= n) {
			if (sieve[j]) {
				sieve[j] = false;
				cnt++;
			}
			
			if (cnt == k) {
				cout << j;
				return 0;
			}
			
			j += i;
		}
	}
}