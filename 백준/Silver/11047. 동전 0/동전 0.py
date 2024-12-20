n, k = map(int, input().split())
data = []
for i in range(n):
  a = int(input())
  data.append(a)
data.sort()
data.reverse()

count = 0

while True:
  for i in data:
    if k // i == 0:
      continue
    elif k // i != 0:
      count += k // i
      k = k % i
  if k == 0:
    break

print(count)