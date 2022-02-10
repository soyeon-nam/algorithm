# python에서 입력은 한 줄 단위로만 받을 수 있습니다.
# python에는 split()이라는 함수가 있습니다. 이 함수는 문자열을 특정 기준으로 잘라주는 함수입니다.
# 예를 들어 다음과 같이 split 함수를 그대로 사용하면, 공백을 기준으로 문자열을 잘라 각 잘려나간 단위가 하나의 원소가 되어 해당 원소들을 가지고 있는 하나의 list가 만들어집니다.
# 따라서 2개의 줄에 걸쳐 입력을 받기 위해서는, 다음과 같이 input() 함수를 2번 사용하면 됩니다.

x, y = 0, 0

dx = [1,  0, -1, 0]
dy = [0, -1,  0, 1]

mapper = {
    "N": 3,
    "E": 0,
    "S": 1,
    "W": 2
}

n = int(input())

for i in range(n):
    c_dir, dist = tuple(input().split())
    dist = int(dist)

    dir_num = mapper[c_dir]
    x, y = x + dx[dir_num] * dist, y + dy[dir_num] * dist
    
print(x, y)