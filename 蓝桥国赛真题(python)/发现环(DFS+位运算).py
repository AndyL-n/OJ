import os
import sys

n = int(input())
n += 1
v = [[] for i in range(n)]

for i in range(1,n):
  a,b = map(int,input().split())
  v[a].append(b)
  v[b].append(a)


q = []
for i in range(1,n):
  if len(v[i]) == 1:
    q.append(i)

while len(q):
  x = q.pop()
  y = v[x].pop()
  v[y].pop(v[y].index(x))
  if (len(v[y]) == 1):
    q.append(y)

for i in range(1,n):
  if len(v[i]) == 2:
    print(i,end=' ')
