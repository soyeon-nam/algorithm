#include <iostream>
#include <vector>

using namespace std;

#define K_MAX	4
#define M_MAX	100
#define N_MAX	12

int	n, m, k;
int	score;

int	moveNum[M_MAX];				// 입력 받은 턴마다 나아 갈 수 있는 거리
int	location[K_MAX];			// k개의 말이 최종적으로 나아간 칸 수
vector<int> moveOrder;			// 어떠한 말이 각 턴에 움직일 지


int		cntScore() {
	int	ret = 0;

	for (int i = 0; i < k; i++) 
		ret += (location[i] >= m);

	return (ret);
}

int		moveMarker() {
	for (int j = 0; j < 4; ++j)
		location[j] = 1;
	for (int i = 0; i < n; ++i) {
		location[moveOrder[i]] += moveNum[i];
	}
	int ret = cntScore();
	return (ret);
}

void		chooseMarker(int cnt) {
	if (cnt == n) {
		score = max(score, moveMarker());
		return;
	}

	for (int i = 0; i < k; i++) {
		moveOrder.push_back(i);
		chooseMarker(cnt + 1);
		moveOrder.pop_back();
	}
}

int		main() {
	cin >> n >> m >> k;
	int input;
	for (int i = 0; i < n; i++)
		cin >> moveNum[i];
	chooseMarker(0);
	cout << score;

	return (0);
}