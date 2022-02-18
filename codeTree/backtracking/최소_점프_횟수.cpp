#include <iostream>
#include <vector>

using namespace std;

#define N_MAX	10

int	n;
int res = INT8_MAX;
int	arr[N_MAX];	
int	location = 1;


void		maxJump(int cnt) {

	if (location >= n) {
		res = min(res, cnt);
	}
	if (cnt == n || location >= n)
		return ;

	
	for (int i = 1; i <= arr[location - 1]; i++) {	
		location += i;
		maxJump(cnt + 1);
		location -= i;
	}
}

int		main() {
	cin >> n ;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	maxJump(0);
	if (res == INT8_MAX)
		res = -1;
	cout << res;

	return (0);
}