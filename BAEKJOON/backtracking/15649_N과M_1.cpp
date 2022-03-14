#include <iostream>

#define MAX_M 8
#define MAX_N 8

using namespace std;

int n, m;
int arr[MAX_M];
bool visited[MAX_N];

void	printArr(){
	for (int i = 0; i < m; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void	findPermutation(int idx){
	if (idx == m)
		return printArr();

	for (int i = 1; i <= n; ++i){
		if (!visited[i - 1]){
			arr[idx] = i;
			visited[i - 1] = 1;
			findPermutation(idx + 1);
			visited[i - 1] = 0;
		}
	}
}

int		main(){
	cin >> n >> m;

	findPermutation(0);

	return 0;
}