// 어떤 경로로 왔는지는 상관 없음
// 상태(마지막으로 방문합 위치, 이동한 경로 상의 숫자 합)만 신경 씀

#include <iostream>

#define MAX_N 1000

using namespace std;

int n;
int num[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

void	initialize() {
	dp[0][0] = num[0][0];

	for (int i = 1; i < n; ++i)
		dp[i][0] = dp[i - 1][0] + num[i][0];

	for (int j = 1; j < n; ++j)
		dp[0][j] = dp[0][j - 1] + num[0][j];	
}

int		main() {
	cin >> n;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j)
			cin >> num[i][j];
	
	initialize();

	for (int i = 1; i < n; ++i)
		for (int j = 1; j < n; ++j)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + num[i][j];

	cout << dp[n - 1][n - 1];
	return (0);
}