n, t = tuple(map(int, input().split()))
grid = [ list(map(int, input().split())) for _ in range(2) ]

def     rotateCB() :
    temp = [grid[0][n - 1], grid[1][n - 1]]
    for line in range(2) :
        for i in range(n - 1, 0, -1) :
            grid[line][i] = grid[line][i - 1]
        grid[line][0] = temp[1 - line]


for _ in range(t) :
    rotateCB()

for elem in grid :
    for num in elem :
        print(num, end = " ")
    print()