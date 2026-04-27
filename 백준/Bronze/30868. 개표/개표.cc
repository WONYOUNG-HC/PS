#include <iostream> 
#include <string>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N / 5; i++)
			cout << "++++ ";
		for (int i = 0; i < N % 5; i++)
			cout << '|';
		cout << "\n";
	}
}