n,k = map(int,input().split())
ans = 0
for i in range(1,n+1):
  if str(bin(i))[2:].count('1') == k:
    ans += 1
print(ans)
