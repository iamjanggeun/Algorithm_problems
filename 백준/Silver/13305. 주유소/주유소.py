N = int(input())
dist = list(map(int, input().split()))
cost = list(map(int, input().split()))

current_cost = cost[0]
result = 0

for i in range(0, N - 1):
  if cost[i] < current_cost:
    current_cost = cost[i]
  result += current_cost * dist[i]

print(result)  