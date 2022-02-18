/*
	그래프 탐색
		1. 시작점으로부터 연결된 모든 정점을 방문하는 것
		2. 단, 동일한 정점을 2번 이상 방문하는 경우는 없어야 함

	인접행렬
		공간 복잡도 : O(V^2)
		시간 복잡도 : O(V^2)

	인접리스트
		공간 복잡도 : O(V + E)
		시간 복잡도 : O(V + E)
*/


#include <iostream>
#include <vector>
// #define MAX_NUM 1000

using namespace std;


int	n, m;
int	res;

// int arr[(MAX_NUM + 1) * (MAX_NUM + 1)];
// int visited[(MAX_NUM + 1) * (MAX_NUM + 1)]; //배열은 전역변수 = 0 자동 초기화

vector<int>arr;
vector<int>visited;

void	DFS(int vtx) {
	for (int nxt = 1; nxt <= n; ++nxt) {
		if (arr[vtx * n + nxt] && !visited[nxt]) {
			visited[nxt] = true;
			++res;
			DFS(nxt);
		}
	}
}

int		main() {
	int x, y;

	cin >> n >> m;
	arr.assign((n + 1) * (n + 1), 0);   
	visited.assign(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		arr[x * n + y] = 1;
		arr[x + y * n] = 1;
	}
	visited[1] = true;
	DFS(1);
	cout << res;

	return (0);	
}