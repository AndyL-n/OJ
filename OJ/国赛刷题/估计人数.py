from math import ceil
n,m = map(int,input().split())
data = [[] for _ in range(n)]
for i in range(n):
  tmp = input()
  for j,k in enumerate(tmp):
    data[i].append(k)

count = 0
for j in range(1,m):
  if data[0][j-1] == '1':
    count += 1
  if data[n-1][j] == '1':
    count += 1
  
for i in range(1,n):
  if data[i-1][m-1] == '1':
    count += 1
  if data[i][0] == '1':
    count += 1

print(ceil(count/2))
