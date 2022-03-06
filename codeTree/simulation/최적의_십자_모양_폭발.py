import copy								# copy 모듈 불러오기

n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

def		inRange(x, y) :
	return 0 <= x and x < n and 0 <= y and y < n


def		bomb(x, y) :
	grid[x][y] = 0


def		resetCol(x, y, temp_grid) :
	for i in range(x, 0, -1) :
		temp_grid[i][y] = temp_grid[i -1][y]
	temp_grid[0][y] = 0
	return temp_grid


def		resetRow(x, y, bombRange, temp_grid) :
	x_bottom = x + bombRange - 1 if inRange(x + bombRange - 1, y) else n - 1
	x_top = x - bombRange + 1 if inRange(x - bombRange, y) else 0
	gap = x_bottom - x_top + 1
	for i in range(x_top - 1 , -1, -1) :
		temp_grid[i + gap][y] = temp_grid[i][y]
	for j in range(gap) :
		temp_grid[j][y] = 0
	return temp_grid


def		bombCross(x, y) :
	bomb_range = grid[x][y]
	temp_grid = copy.deepcopy(grid)							# deep copy vs shallow copy
	for i in range(y - bomb_range + 1, y + bomb_range) :
		if inRange(x, i) and i != y:
			temp_grid = resetCol(x, i, temp_grid)
	temp_grid = resetRow(x, y, bomb_range, temp_grid)
	return temp_grid


def		cntPair(temp_grid) :
	cnt = 0
	for i in range(n - 1) :
		for j in range(n) :
			cnt += 1 if temp_grid[i][j] == temp_grid[i + 1][j] != 0 else 0
	for i in range(n) :
		for j in range(n - 1) :
			cnt += 1 if temp_grid[i][j] == temp_grid[i][j + 1] != 0 else 0
				
	return cnt

def		findOptimumCoor() :
	max = 0
	for i in range(n) :
		for j in range(n) :
			temp_grid = bombCross(i, j)
			temp_max = cntPair(temp_grid)
			max = temp_max if temp_max > max else max
	return max


print(findOptimumCoor())