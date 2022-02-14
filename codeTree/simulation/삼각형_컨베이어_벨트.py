n, t = tuple(map(int, input().split()))
grid = [ list(map(int, input().split())) for _ in range(3) ]

def     rotateCB() :
    temp = [grid[i][n - 1] for i in range(3)]
    for line in range(3) :
        for i in range(n - 1, 0, -1) :
            grid[line][i] = grid[line][i - 1]
        grid[line][0] = temp[(line + 2) % 3]


for _ in range(t) :
    rotateCB()

for elem in grid :
    for num in elem :
        print(num, end = " ")
    print()