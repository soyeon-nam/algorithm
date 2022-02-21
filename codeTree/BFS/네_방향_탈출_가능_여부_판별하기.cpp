#include <iostream>
#include <queue>

#define MAX_N 100
#define MAX_M 100

using namespace std;

int n, m;
int a[MAX_N][MAX_M];

queue<pair<int, int> > q;
bool visited[MAX_N][MAX_M];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
    return InRange(x, y) && a[x][y] && !visited[x][y];
}

void BFS() {
    while(!q.empty()) {
        pair<int, int> curr_pos = q.front();
        int x = curr_pos.first, y = curr_pos.second;
        q.pop();

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if(CanGo(nx, ny)){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }

}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    BFS();

    cout << visited[n - 1][m - 1];

    return 0;
}