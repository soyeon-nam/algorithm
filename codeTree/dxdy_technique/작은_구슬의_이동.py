dy = [1, 0, 0, -1]
dx = [0, -1, 1, 0]

mapper = {
    "L" : 3,
    "R" : 0,
    "U" : 1,
    "D" : 2
} 

n, time = tuple(map(int, input().split()))
x, y, dir_start = tuple(input().split())
x_index, y_index, dir_curr = int(x) - 1 , int(y) - 1, mapper[dir_start]


def in_range(x, y):
    return 0 <= x and x < n and 0 <= y and y < n


for _ in range(time) :
    x_temp, y_temp = x_index + dx[dir_curr], y_index + dy[dir_curr]
    if in_range(x_temp, y_temp) :
        x_index, y_index = x_temp, y_temp
    else :
        dir_curr = 3 - dir_curr

print(x_index + 1, y_index + 1)