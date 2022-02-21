#include <iostream>
#include <queue>

#define MAX_N 100
#define DIR_NUM 4

using namespace std;

int	n, k;
int	grid[MAX_N][MAX_N];
int	visited[MAX_N][MAX_N];

queue<pair<int, int> > bfs_q;

bool		isRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

bool		isValid(int x, int y) {
	return (isRange(x, y) && !grid[x][y] && !visited[x][y]); 
}

void		bfs() {

	while (!bfs_q.empty()) {
		pair<int, int> curr_pos = bfs_q.front();
		int x = curr_pos.first, y = curr_pos.second;
		bfs_q.pop();

		int dx[DIR_NUM] = {1, -1, 0, 0};
		int dy[DIR_NUM] = {0, 0, 1, -1};

		for (int i = 0; i < DIR_NUM; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (isValid(nx, ny)){ 
				bfs_q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
			}
		}
	}
}


int		main() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j)
			cin >> grid[i][j];

	while (k--) {
		int x, y;
		cin >> x >> y;
		bfs_q.push(make_pair(x - 1, y - 1));
		visited[x - 1][y - 1] = 1;
	}

	bfs();

	int res = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(visited[i][j])
                res++;
    
	cout << res;
	
	return (0);
}