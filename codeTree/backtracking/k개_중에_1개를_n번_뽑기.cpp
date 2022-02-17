#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> arr_num;	

void	print_arr() {
	for (int i = 0; i < n; i++)
		cout << arr_num[i] << " ";
	cout << endl;
}

void	pickOne(int cnt) {
	if (cnt == n) {
		print_arr();
		return;
	}
	
	for (int i = 1; i <= k; i++) {
		arr_num.push_back(i);
		pickOne(cnt + 1);
		arr_num.pop_back();
	}

}

int		main() {
	cin >> k >> n;

	pickOne(0);
	return (0);
}