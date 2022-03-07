#include <iostream>

#define MAX_N 10
using namespace std;

int n, k;
int coins[MAX_N];

int ret;

int		main() {
	cin >> n >> k;
	for (int i = n-1; i >= 0; --i)
		cin >> coins[i];

	int j = 0;
	while (k > 0) {
		ret += k / coins[j];
		k %= coins[j++];
	}

	cout << ret;
	
	return 0;
}