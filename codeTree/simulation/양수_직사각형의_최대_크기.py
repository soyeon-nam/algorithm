n, m = tuple(map(int, input().split()))
grid = [tuple(map(int, input().split())) for _ in range(n)]


def		findBiggestHeight(x, y, length) : 
	max_height = 1
	if n - x - 1 == 0 :							# 1줄 밖에 없는 경우

		return length
	for i in range(1, n - x) :
		for j in range(length) :
			if grid[x + i][y + j] <= 0 :
				return max_height * length
		max_height += 1
	return max_height * length

def		findEachSideLength(length) :				#양수 가로 길이를 기준으로 넓혀가기 위한
	max = -1
	for x in range(n) :
		for y in range(m - length + 1) :
			i = 0
			while i < length and grid[x][y + i] > 0 :
				i += 1
				if (i == length) : 
					max_temp = findBiggestHeight(x, y, length)
					if max_temp > max :
						max = max_temp
						break
	return max


def		findBiggestSquare() :
	max = -1
	for i in range(1, n+1) :
		max_temp = findEachSideLength(i)
		if max_temp > max :
			max = max_temp
	return max

print(findBiggestSquare())