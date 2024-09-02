s = list(map(int, input().split()))
chess = [1, 1, 2, 2, 2, 8]
value = [0]*len(s)
for i in range(len(s)):
    print(chess[i] - s[i], end = " ")