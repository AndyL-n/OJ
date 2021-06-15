n,m,k = map(int,input().split())

data = list(map(int,input().split()))

for _ in range(m):
  x,y = map(int,input().split())

  tmp = []
  for index,val in enumerate(data):
    val += x
    if val <= 0:
      continue
    elif val <= k:
      tmp.append(val)
    else:
      tmp.append(k)
      val -= k
      for _ in range(val):
        tmp.append(1)
  data = tmp
  if y > 0:
    data.append(y)
  print(sum(data)%998244353)

