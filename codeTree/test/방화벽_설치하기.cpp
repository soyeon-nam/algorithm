#include <iostream>
#include <vector>
#include <queue>

#define MAX_NM 8

using namespace std;

int n, m;
int max_res;

int	grid[MAX_NM][MAX_NM];
int	fired[MAX_NM][MAX_NM];

vector<pair<int, int> > empty;
vector<int> selected_idx;

queue<pair<int, int> > bfs_q;

void	initFired() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			fired[i][j] = grid[i][j];
}

void	putFirewall() {
	for (int i = 0; i < 3; ++i) {
		pair<int, int> empty_area = empty[selected_idx[i]];
		int x = empty_area.first, y = empty_area.second;
		fired[x][y] = 1;
	}
}

int		inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m; 
}

void	BFS() {
	while (!bfs_q.empty()) {
	    pair<int, int> curr_pos = bfs_q.front();
        int x = curr_pos.first, y = curr_pos.second;
        bfs_q.pop();

		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
	
            if(inRange(nx, ny) && fired[nx][ny] == 0){
                bfs_q.push(make_pair(nx, ny));
                fired[nx][ny] = 2;

		    }
		}
	}
}

void	installFirewall() {
	initFired();
	putFirewall();

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (fired[i][j] == 2){
				bfs_q.push(make_pair(i, j));
				BFS();
			}
			
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (fired[i][j] == 0)
				++cnt;

	max_res = max(max_res, cnt);
}

void	pickFirewall(int idx, int cnt) {
	if (cnt == 3) {
		installFirewall();
		return ;
	}
	if (cnt > 4 || idx == empty.size())
		return ;

	selected_idx.push_back(idx);
	pickFirewall(idx + 1, cnt + 1);
	selected_idx.pop_back();

	pickFirewall(idx + 1, cnt);
}

int		main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];

			if (grid[i][j] == 0)
				empty.push_back(make_pair(i, j));
		}
	
	pickFirewall(0, 0);

	cout << max_res;
	return (0);
}