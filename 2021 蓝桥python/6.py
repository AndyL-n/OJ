from math import sqrt,ceil
n = int(input())

for _ in range(n):
  l,r = map(int,input().split())
  a,b = round(sqrt(l*2)),round(sqrt(r*2))
  ans = 0
  for i in range(a,b):
    ans += i*(i+1)//2
  begin_a = l - (a-1)*a//2
  begin_b = r - (b-1)*b//2
  ans += begin_b*(begin_b+1)//2 -begin_a*(begin_a+1)//2 + begin_a
  print(ans)
