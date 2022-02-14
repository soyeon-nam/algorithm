import copy # copy 모듈 불러오기

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
	temp_grid = copy.deepcopy(grid)
	print(temp_grid, "\n\ngrid\n", grid)
	for i in range(y - bomb_range + 1, y + bomb_range) :
		if inRange(x, i) and i != y:
			temp_grid = resetCol(x, i, temp_grid)
	temp_grid = resetRow(x, y, bomb_range, temp_grid)
	return temp_grid


def		cntPair(temp_grid) :
	cnt = 0
	# if n >= 3 :
	for i in range(n - 1) :
		for j in range(n) :
			cnt += 1 if temp_grid[i][j] == temp_grid[i + 1][j] != 0 else 0
	for i in range(n) :
		for j in range(n - 1) :
			cnt += 1 if temp_grid[i][j] == temp_grid[i][j + 1] != 0 else 0
				
	return cnt

def		printResult(grid1) :
	print()
	for line in grid1 :
		for elem in line :
			print(elem, end = " ")
		print()

def		findOptimumCoor() :
	max = 0
	for i in range(n) :
		for j in range(n) :
			if n <= 2 :
				temp_max = cntPair(grid)   					#테케 n = 2짜리, bomb 안 터뜨려도 되나?
			else :
				temp_grid = bombCross(i, j)
				# printResult(temp_grid)
				temp_max = cntPair(temp_grid)
			max = temp_max if temp_max > max else max
	return max


print(findOptimumCoor())
		

















































# n = int(input())
# grid = [list(map(int, input().split())) for _ in range(n)]


# def		validRange(x, y, bomb_range) :
# 	top = 0 if x - bomb_range < 0 else x - bomb_range
# 	bottom = n - 1 if x + bomb_range >= n else x + bomb_range
# 	left = 0 if y - bomb_range < 0 else y - bomb_range
# 	right = n - 1 if y + bomb_range >= n else y + bomb_range 
# 	return top, bottom, left, right


# def		resetCol(x, y, grid) :
# 	for i in range(x, 0, -1) :
# 		grid[i][y] = grid[i - 1][y]
# 	grid[0][y] = 0 
# 	return grid


# def		resetRow(x_top, x_bottom, y, temp_grid) :
# 	gap = x_bottom - x_top + 1
# 	for i in range(x_top - 1, -1, -1) :
# 		temp_grid[i + gap][y] = temp_grid[i][y]
# 	for j in range(gap) :
# 		temp_grid[j][y] = 0
# 	return temp_grid


# def		bombCross(x, y) :
# 	cnt = 0
# 	bomb_range = grid[x][y] - 1
# 	temp_grid = grid
# 	top, bottom, left, right = validRange(x, y, bomb_range)

# 	for i in range(left, y) :
# 		temp_grid = resetCol(x, i, temp_grid)
# 	for j in range(y + 1, right + 1) :
# 		temp_grid = resetCol(x, j, temp_grid)
# 	temp_grid = resetRow(top, bottom, y, temp_grid)

# 	return temp_grid


# def		cntPair(temp_grid) :
# 	cnt = 0
# 	for i in range(n - 1) :
# 		for j in range(n) :
# 			cnt += 1 if temp_grid[i][j] == temp_grid[i + 1][j] else 0
# 	for i in range(n) :
# 		for j in range(n - 1) :
# 			cnt += 1 if temp_grid[i][j] == temp_grid[i][j + 1] else 0
# 	return cnt


# def		findOptimumCoor() :
# 	max = 0
# 	for i in range(n) :
# 		for j in range(n) :
# 			temp_grid = bombCross(i, j)
# 			temp_max = cntPair(temp_grid)
# 			max = temp_max if temp_max > max else max
# 	return max


# print(findOptimumCoor())