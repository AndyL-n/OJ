n = int(input())
var = list(map(int,input().split()))
dpx, dps = [1 for _ in range(n+1)],[0 for _ in range(n+1)]


dpx[1],dps[1] = var[0],var[0]
for i in range(2,n+1):
  dpx[i] = dpx[i-1] * var[i-1]
  dps[i] = dps[i-1] + var[i-1]
  
ans = 0
for i in range(1,n+1):
  for j in range(i,n+1):
    if dpx[j]//dpx[i-1] == dps[j] - dps[i-1]:
      ans += 1
print(ans)

