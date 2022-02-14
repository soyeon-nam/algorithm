cnt_left = n = int(input())
jenga = [int(input()) for _ in range(n)]


def		takeOutBlock(start_idx, end_idx) :
	temp_jenga = []
	i = 0
	while i < cnt_left :						# 탈출문, 증가 연산 실수 주의(TLE)
		if start_idx == i:
			i = end_idx + 1 
		else :
			temp_jenga.append(jenga[i])
			i += 1

	return temp_jenga

def		playJenga() :
	global cnt_left
	global jenga
	for _ in range(2) :
		start, end = tuple(map(int, input().split()))
		jenga = takeOutBlock(start - 1 , end - 1)
		cnt_left = cnt_left - (end - start + 1)

def		printJengaInfo() :
	print(cnt_left)
	for elem in jenga :
		print(elem)

playJenga()
printJengaInfo()