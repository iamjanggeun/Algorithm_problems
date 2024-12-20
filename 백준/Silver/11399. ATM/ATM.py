N = int(input())
data = list(map(int, input().split()))

data.sort()

result = 0

# 런타임 에러
for i in range(N):
  result += data[i] * (N-i)

# subset = 0

# for i in range(N):
#   subset += data[i]
#   result += subset

print(result)