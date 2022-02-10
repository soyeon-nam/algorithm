dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]

mapper = {
    "N" : 3,
    "E" : 0,
    "S" : 2, 
    "W" : 1
}
def regressTime() :
	command_num = int(input())
	x, y = 0, 0 
	elapsed_time = 0
	for _ in range(command_num) :
		direction, size = tuple(input().split())
		size = int(size)
		direction = mapper[direction]
		for _ in range(size) :
			x, y = x + dx[direction], y + dy[direction]
			elapsed_time += 1
			if x == 0 and y == 0 :
				return (elapsed_time)
	return (-1)

print(regressTime())