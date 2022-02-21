#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string	g_input;
int		g_size;
int		g_max = INT8_MIN;
vector<int> mapper;

// abcdef
// +-*

// 재귀로 모든 케이스 다 다녀보면서 마지막에 계산해서 max 업데이트


int		convertAlpha(char opr) {
    return (mapper[opr - 'a']);
}

int		calculate(int ret, char opr, int num) {
	switch (opr) {
		case '+':
			ret += num;
			break;
		case '-':
			ret -= num;
			break;
		default :
			ret *= num;
			break;
	}
	return (ret);
}
int		calculateAll() {
	int ret = convertAlpha(g_input[0]);
	for (int i = 0; i < g_size / 2; i++)
		ret = calculate(ret, g_input[2 * i + 1], convertAlpha(g_input[2 * i + 2]));
	return (ret);
}

void		findBiggestNum(int num) {
	if (num == 6) {
		int temp = calculateAll();
		if (temp > g_max)
			g_max = temp;
		return ;
	}
	
	for (int i = 1; i <= 4; i++) {
		mapper.push_back(i);
		findBiggestNum(num + 1);
		mapper.pop_back();
	}
}

int		main() {
	cin >> g_input;
	g_size = g_input.length();
	findBiggestNum(0);
	cout << g_max;
	return (0);
}