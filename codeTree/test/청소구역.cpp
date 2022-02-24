#include <iostream>

#define MAX_N 101

using namespace std;

int a, b, c, d;
int cnt;
int arr[MAX_N];

int		main() {
	cin >> a >> b >> c >> d;

	for (int i = a; i < b; ++i)
		arr[i] = 1;

	for (int i = c; i < d; ++i)
		arr[i] = 1;
	
	for (int j = 0; j <= MAX_N; ++j)
		if (arr[j] == 1)
			cnt++;

    cout << cnt;

	return (0);
}