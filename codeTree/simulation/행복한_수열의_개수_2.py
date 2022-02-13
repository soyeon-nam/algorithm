n, m = tuple(map(int, input().split()))
grid = [list(map(int, input().split())) for _ in range(n)]
seq = [0 for _ in range(n)]

def		isSuccession(col, seq) :				# 각 줄을 담는 리스트를 생성해 행/열 무관하게 행복한 수열 확인
	curr = -1
	cnt = 1
	for i in range(n) :
		prev = curr
		curr = seq[i]
		cnt = cnt + 1 if curr == prev else 1
		if cnt == m :
			return True
	return False


def		cntSuccession() :
	cnt = 0

	for i in range(n) :
		seq = grid[i][:]
		if isSuccession(i, seq) : 
			cnt += 1

	for j in range(n) :
		for k in range(n) :
			seq[k] = grid[k][j]
		if isSuccession(i, seq) : 
			cnt += 1
	return (cnt)

print(cntSuccession())