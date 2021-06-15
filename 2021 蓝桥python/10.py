n, m = map(int,input().split())
s = input()
data = []
for i in s:
  if i == '(':
    data.append(0)
  else:
    data.append(1)
for _ in range(m):
  var = list(map(int,input().split()))
  if var[0] == 1:
    l,r = var[1:3]
    for i in range(l-1,r):
      data[i] ^= 1
  elif var[0] == 2:
    l = var[1] - 1
    tmp = 0
    ans = 0
    for i in range(l,len(data)):
      if tmp == 0 and data[i]:
        break
      tmp += -1 if data[i] else 1
      if tmp == 0:
        ans = i
    if ans:
      print(ans+1)
    else:
      print(0)
