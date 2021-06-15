import sys
import os
import functools

n = int(input())  
val = [[] for i in range(n)]
for i in range(n):
  val[i] = list(map(int,input().split()))
  val[i].append(sum(val[i]))

val.sort(key=lambda x: x[2])
val.sort(key=lambda x: x[3])

ans = 0
t = 0
for i,val in enumerate(val):
  ans += t + sum(val[:-2])
  t += sum(val[:-1])
  
print(ans)


