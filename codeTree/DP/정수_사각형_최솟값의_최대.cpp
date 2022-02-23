#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int	grid[MAX_N][MAX_N];
int	dp[MAX_N][MAX_N];

void	initialize() {
	dp[0][0] = grid[0][0];

	for (int i = 1; i < n; ++i)
		dp[0][i] = min(grid[0][i], dp[0][i - 1]);

	for (int j = 1; j < n; ++j)
		dp[j][0] = min(grid[j][0], dp[j - 1][0]);	
}

int		main() {
	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> grid[i][j];

	initialize();

	for (int i = 1; i < n; ++i)
		for (int j = 1; j < n; ++j)
			dp[i][j] = min(max(dp[i - 1][j], dp[i][j - 1]),grid[i][j]);

	cout << dp[n - 1][n - 1];
	return (0);
}
