#include <iostream>

using namespace std;

int dp[20];

int		main() {
	int n;

	cin >> n;

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n + 1; ++i)
		for (int j = 1; j <= n; ++j)
			dp[i] += dp[j] * dp[i - j];

	cout << dp[n + 1];
	return (0);
}


/*
	루트 한 쪽 아래에 원소가
		1개일 때   --> 1
		2개일 때  --> 1 
		3개일 때  --> 2 = 1 * 1 + 1 * 1
		4개일 때  --> 5 = 1 * 2 + 1 * 1 + 2 * 1
		5개일 때  --> 14 = 1 * 5 + 2 * 2 + 5 * 1
		6개일 때  --> 42

	dp[1] = 1
	dp[2] = 1
	dp[3] = 2
	dp[4] = 14
	dp[5] = 42 

*/