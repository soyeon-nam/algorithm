n, m = tuple(map(int, input().split()))
square = [ [0] * m
	for _ in range(n)
]
# square = [ [0] * m ] * n -- time over

def		in_range(x, y) :
	return 0 <= x and x < n and 0 <= y and y < m

def		is_dup(x, y) :
	return square[x][y] != 0


x, y = 0, 0				# 시작 지점 (0, 0)
dir_curr = 0			# 0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

square[0][0] = 1		# 시작 지점 값

for i in range(2, n * m + 1) :
	x_temp, y_temp = x + dx[dir_curr], y + dy[dir_curr]
	if in_range(x_temp, y_temp) == False or is_dup(x_temp, y_temp) :
		dir_curr = (dir_curr + 1) % 4
	x, y = 	x + dx[dir_curr], y + dy[dir_curr]
	square[x][y] = i

# 출력
for i in range (n) :
	for j in range(m) :
		print(square[i][j], end = " ")
	print()