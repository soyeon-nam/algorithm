dx, dy = [0, 1, 0 , -1], [1, 0, -1, 0]

def move(x, y, dir_curr, command) :
    if command == "F" :
        x, y = x + dx[dir_curr], y + dy[dir_curr]
    elif command == "L" :
        dir_curr = (dir_curr + 3) % 4
    else :
        dir_curr = (dir_curr + 1) % 4
    return x, y, dir_curr


def regressTime() :
    x, y = 0, 0
    dir_curr = 3
    command = tuple(input())
    num = len(command)
    for i in range(num) :
        x, y, dir_curr = move(x, y, dir_curr, command[i])
        if x == 0 and y == 0 :
            return (i + 1)
    return (-1)


print(regressTime())