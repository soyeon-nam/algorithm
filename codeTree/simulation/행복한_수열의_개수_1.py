n, m = tuple(map(int, input().split()))
grid = [tuple(map(int, input().split())) for _ in range(n)]

# 가로와 세로를 확인하는 함수를 따로 만듦
def		isSuccessionCol(col) :
	curr = -1
	cnt = 1
	for i in range(n) :
		prev = curr
		curr = grid[col][i]
		cnt = cnt + 1 if curr == prev else 1
		if cnt == m :
			return True
	return False


def		isSuccessionRow(row) :
	curr = -1
	cnt = 1
	for i in range(n) :
		prev = curr
		curr = grid[i][row]
		cnt = cnt + 1 if curr == prev else 1
		if cnt == m :
			return True

	return False

def		cntSuccession() :
	cnt = 0
	for i in range(n) :
		if isSuccessionCol(i) :
			cnt += 1
	for j in range(n) :
		if isSuccessionRow(j) : 
			cnt += 1
	return (cnt)


print(cntSuccession())