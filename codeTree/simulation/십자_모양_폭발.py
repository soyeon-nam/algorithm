n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]
x, y = tuple(map(int, input().split()))
x, y = x - 1, y - 1

def		inRange(x, y) :
	return 0 <= x and x < n and 0 <= y and y < n


def		bomb(x, y) :
	grid[x][y] = 0


def		resetCol(x, y) :
	for i in range(x, 0, -1) :
		grid[i][y] = grid[i -1][y]
	grid[0][y] = 0


def		resetRow(x, y, bombRange) :
	x_bottom = x + bombRange - 1 if inRange(x + bombRange - 1, y) else n - 1
	x_top = x - bombRange + 1 if inRange(x - bombRange, y) else 0
	gap = x_bottom - x_top + 1
	for i in range(x_top - 1 , -1, -1) :
		grid[i + gap][y] = grid[i][y]
	for j in range(gap) :
		grid[j][y] = 0


def		bombCross() :
	bomb_range = grid[x][y]
	for i in range(y - bomb_range + 1, y + bomb_range) :
		if inRange(x, i) and i != y:
			resetCol(x, i)
	resetRow(x, y, bomb_range)


def		printResult() :
	for line in grid :
		for elem in line :
			print(elem, end = " ")
		print()


bombCross()
printResult()
