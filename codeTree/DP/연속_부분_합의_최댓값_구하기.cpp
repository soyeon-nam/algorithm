// 상태(선택한 연속 부분 수열의 마지막 원소의 위치, 현재 얻은 점수)

#include <iostream>

#define MAX_N 100000

using namespace std;

int	n;
int	arr[MAX_N];
int	dp[MAX_N];

int		main() {
	cin >> n;
	
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	for(int k = 1; k <= n; ++k)
		dp[k] = INT8_MIN;

	dp[0] = arr[0];
	for (int j = 0; j < n; ++j)
		dp[j] = max(dp[j - 1] + arr[j], arr[j]);

	int res = INT8_MIN;
	for(int i = 0; i < n; ++i)
		res = max(res, dp[i]);	

	cout << res;
	return (0);
}