#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

vector<bool> prime_nums;

void Eratosthenes(int n);
void GetNum(int n);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	
	Eratosthenes(n);
	
	GetNum(n);
}

void Eratosthenes(int n) {
	prime_nums.resize(n + 1, true);
	
	for (int i = 2; i <= sqrt(n); i++) {
		if (!prime_nums[i]) {
			continue;
		}
		
		int j = i + i;
		while (j <= n) {
			prime_nums[j] = false;
			j += i;
		}
	}
}

void GetNum(int n) {
	for (int i = 2; i <= n; i++) {
		if (!prime_nums[i]) {
			continue;
		}
		
		int k = i;
		set<int> s;
		while (true) {
			int d = 10, sum = 0;
			while (k > 0) {
				sum += (k % 10) * (k % 10);
				k /= 10;
			}
			
			if (sum == 1) {
				cout << i << '\n';
				break;
			}
			if (s.find(sum) != s.end()) {
				break;
			}
			
			s.insert(sum);
			
			k = sum;
		}
	}
}