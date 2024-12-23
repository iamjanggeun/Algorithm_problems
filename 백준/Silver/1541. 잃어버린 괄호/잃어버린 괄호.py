eqt = input().split('-')
num = []

for i in eqt:
  sum = 0
  subset = i.split('+')
  for k in subset:
    sum += int(k)
  num.append(sum)

result = num[0]

for i in range(1, len(num)):
  result -= num[i]

print(result)