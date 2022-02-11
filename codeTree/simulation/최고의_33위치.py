n = int(input())

def     initGrid() :
    grid = [tuple(map(int, input().split())) for _ in range(n)]     # index 실수 주의
    return grid                                                     # 파이썬은 이중배열 괄호 하나로 불가

def     cntCoin(x, y) :
    cnt = 0
    for i in range(3) :
        for j in range(3) :
            if grid[x + i][y + j] == 1 :
                cnt += 1
    return cnt


grid = initGrid()
max_cnt = 0

for i in range(n - 2) :
    for j in range(n - 2) :
        curr_cnt = cntCoin(i, j)            # 시작점을 넘겨줌
        if max_cnt < curr_cnt :
            max_cnt = curr_cnt

print(max_cnt)