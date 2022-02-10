x, y = 0, 0
dir_num = 3

dx = [1,  0, -1, 0]
dy = [0, -1,  0, 1]

commands = input()

for command in commands :
   if command == 'R' :
      dir_num = (dir_num + 1) % 4
   elif command == 'L' : 
      dir_num = (dir_num + 3) % 4
   else : 
      x, y = x + dx[dir_num], y + dy[dir_num]

print(x, y)