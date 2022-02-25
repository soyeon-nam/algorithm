#include <iostream>

#define MAX_N 1000

using namespace std;

char a[MAX_N];
char b[2];
int	cnt;

int		main() {
	cin >> a >> b;

	int i = -1;
	while (a[++i])
		if (a[i] == b[0])
			if (a[i + 1] == b[1])
				++cnt;
	cout << cnt;

	return (0);
}