N = int(input())
data = list(map(int, input().split()))

data.sort()

result = 0

for i in range(N):
  result += data[i] * (N-i)

print(result)