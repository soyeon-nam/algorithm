dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]

n, m = tuple(map(int, input().split()))
coor = [ [0] * n
    for _ in range(n)
]


def inRange(x, y) :
    return 0 <= x and x < n and 0 <= y and y < n


def cntAdjacent(x, y) :
    cnt = 0
    for i in range(4) :
        nx, ny = x + dx[i], y + dy[i]
        if inRange(nx, ny) and coor[nx][ny] == 1:
            cnt += 1
    return (cnt)


for _ in range(m) :
    x, y = tuple(map(int, (input().split())))
    x, y = x - 1, y - 1
    coor[x][y] = 1
    print(1 if cntAdjacent(x, y) == 3 else 0)