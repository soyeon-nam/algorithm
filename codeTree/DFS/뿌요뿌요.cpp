#include <iostream>

#define MAX_N 100

using namespace std;

int n, cnt_pop_space, max_space_size;
int curr_cnt = 1;
int arr[(MAX_N + 1)][(MAX_N + 1)];
int visited[(MAX_N + 1)][(MAX_N + 1)];

bool 	inRange(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= n);
}

bool	isValid(int x, int y) {
	if (!inRange(x, y) || visited[x][y])
		return (0);
	return (1);
}

void		dfs(int x, int y, int num) {
	int	dx[4] = {0, 1, 0, -1};
	int	dy[4] = {1, 0, -1, 0};

	for (int i = 0; i < 4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isValid(nx, ny) && arr[nx][ny] == num) {
			++curr_cnt;
			visited[nx][ny] = 1;
			dfs(nx, ny, num);
		}
	}
}

int		main() {
	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> arr[i][j];
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (!visited[i][j]) {
				visited[i][j] = 1;
				dfs(i, j, arr[i][j]);
				max_space_size = max(curr_cnt, max_space_size);
				cnt_pop_space += (curr_cnt >= 4) ? 1 : 0;
				curr_cnt = 1;
			}
		}
	cout << cnt_pop_space << " " << max_space_size;
	return (0);
}