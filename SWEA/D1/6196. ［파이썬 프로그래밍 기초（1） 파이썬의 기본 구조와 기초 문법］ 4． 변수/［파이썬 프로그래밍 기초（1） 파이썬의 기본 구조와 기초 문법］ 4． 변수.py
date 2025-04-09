#a = int(input())
#answer = a + (a*10 + a) + (a*100 +a*10 + a) + (a*1000 +a*100 +a*10 + a)
#print(answer)

a = str(input())
ans = 0

for i in range(1, 5):
    ans += int(a*i)
print(ans)