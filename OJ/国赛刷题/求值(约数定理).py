ans = 0
for i in range(1,50000):
  ans = 0
  for j in range(1,i):
    if i % j == 0:
      ans += 1
  if ans == 100:
    print(i)
    break
  else:
    print(i,ans)
