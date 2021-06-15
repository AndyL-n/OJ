from math import hypot
var = list(map(int,input().split()))
l,r,d,w = var[0],var[1],var[2],var[3]
L = var[4:4+l]
R = var[4+l:]
print(l,r,d,w)
print(L)
print(R)
##l,r,d,w = map(int,input().split())
##L = list(map(int,input().split()))
##R = list(map(int,input().split()))

dp = [[[10**10, 10**10] for _ in range(len(R)+1)] for _ in range(len(L)+1)]

dp[1][0][0] = hypot(w/2,L[0])
dp[0][1][1] = hypot(w/2,R[0])

for i in range(0,len(L)+1):
  for j in range(0,len(R)+1):
    if i + j <= 1:
      continue
    if i:
      dp[i][j][0] = min(dp[i-1][j][0] + L[i-1] - L[i-2],dp[i-1][j][1] + hypot(w,abs(L[i-1] - R[j-1])))
    if j:
      dp[i][j][1] = min(dp[i][j-1][1] + R[j-1] - R[j-2],dp[i][j-1][0] + hypot(w,abs(L[i-1] - R[j-1])))

##for i in dp:
##  print(i)
##print(dp[len(L)][len(R)][0],hypot(w / 2.0, d - L[len(L)-1]),dp[len(L)][len(R)][1],hypot(w / 2.0, d - R[len(R)-1]))
print('%.2f'%min(dp[len(L)][len(R)][0] + hypot(w / 2.0, d - L[len(L)-1]),dp[len(L)][len(R)][1] + hypot(w / 2.0, d - R[len(R)-1])))

