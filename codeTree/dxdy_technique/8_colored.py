dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]

n, m = tuple(map(int, input().split()))
coor = [ [0] * n
    for _ in range(n)
]

def checkAdjacent(x, y) :
    ret = 0
    for i in range(4) :
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx and nx < n and 0 <= ny and ny < n :
            ret += 1 if coor[nx][ny] == 1 else 0
    return (True if ret >= 3 else False)


for _ in range(m) :
    x, y = tuple(map(int, (input().split())))
    x, y = x - 1, y - 1
    coor[x][y] = 1
    print(1 if checkAdjacent(x, y) == True else 0)