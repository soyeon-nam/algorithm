#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 8
#define DIR_NUM 4

using namespace std;

int n, k, u, d;
int grid[MAX_N][MAX_N];

int max_cnt;

vector<int> start_pos;
vector<pair<int, int> > selected_cities;

queue<pair<int, int> > q;
bool visited[MAX_N][MAX_N];

bool	inRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool	validGap(int curr, int nxt) {
	return (u <= abs(curr - nxt) && abs(curr - nxt) <= d);
}

bool isValid(int x, int y) {
    return inRange(x, y) && !visited[x][y];
}

void	BFS() {
	while (!q.empty()) {
		pair<int, int> curr_pos = q.front();
		int x = curr_pos.first, y = curr_pos.second;
		visited[x][y] = 1;
		q.pop();

		int dx[DIR_NUM] = {1, -1, 0, 0};
		int dy[DIR_NUM] = {0, 0, 1, -1};

        for(int dir = 0; dir < DIR_NUM; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if(isValid(nx, ny) && validGap(grid[x][y], grid[nx][ny])){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
	}
}

int		calc() {
	for (int i = 0; i < k; ++i) {
		q.push(selected_cities[i]);
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			visited[i][j] = 0;

	BFS();

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if(visited[i][j])
				++cnt;

	return cnt;
}

void	findMax(int idx, int cnt) {
    if (cnt > k)
        return ;
	if (idx == n * n) {
		if (cnt == k)
			max_cnt = max(max_cnt, calc());
		return ;
	}

	selected_cities.push_back(make_pair(idx / n, idx % n));
	findMax(idx + 1, cnt + 1);
	selected_cities.pop_back();

	findMax(idx + 1, cnt);
}

int		main() {
	cin >> n >> k >> u >> d;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			cin >> grid[i][j];

	findMax(0, 0);
	cout << max_cnt;

	return (0);
}