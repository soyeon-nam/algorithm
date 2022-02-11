n, r, c, = tuple(map(int, input().split()))
r_idx, c_idx = r - 1, c - 1
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

def	initGrid() : 
	grid = [ tuple(map(int, input().split())) 
		for _ in range(n)
	]
	return grid

def		inRange(x, y) :
	return 0 <= x and x < n and 0 <= y and y < n

def		moveBigNum(r, c, grid) :
	curr_num = grid[r][c]
	for i in range(4) :
		nx, ny = r + dx[i], c + dy[i]
		if inRange(nx, ny) and (curr_num < grid[nx][ny]) :
			return nx, ny
	return -1, -1

grid = initGrid()
log = [grid[r_idx][c_idx]]
while 1 :
	r_idx, c_idx = moveBigNum(r_idx, c_idx, grid)
	if r_idx == -1 and c_idx == -1 :
		break
	log.append(grid[r_idx][c_idx])

for element in log :
	print(element, end = " ")