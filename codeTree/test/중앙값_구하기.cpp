#include <iostream>

#define MAX_N 

using namespace std;

int a, b, c;

int		main() {
	cin >> a >> b >> c;
	int ret;
	if (a < b && b < c)
		ret = b;
	if (c < b && b < a)
		ret = b;
	else if (c < a && a < b)
		ret = a;
	else if (b < a && a < c)
		ret = a;
	else if (a < c && c < b)
		ret = c;
	else if (b < c && c < a)
		ret = c;

	cout << ret;

	return (0);
}