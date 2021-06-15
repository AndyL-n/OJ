import os
import sys

a,b = [],[]
s = input()
tmp = ""
for i in s:
  if ord(i) in range(65,91):
    if tmp != "":
      a.append(tmp)
    tmp = i
  else:
    tmp += i
a.append(tmp)

s = input()
tmp = ""
for i in s:
  if ord(i) in range(65,91):
    if tmp != "":
      b.append(tmp)
    tmp = i
  else:
    tmp += i
b.append(tmp)
dp = [[0 for i in range(len(b)+1)]for i in range(len(a)+1)]
for i,aa in enumerate(a):
  for j,bb in enumerate(b):
    if aa == bb:
      dp[i+1][j+1] = dp[i][j] + 1
    else:
      dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j])

print(dp[len(a)][len(b)])
