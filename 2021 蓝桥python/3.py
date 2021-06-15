from math import sqrt
count = 0
for _ in range(7670):
  s = input()
  ans = 0
  for val in s:
    if val == '/':
      continue
    else:
      ans += int(val)
  if round(sqrt(ans))**2 == ans:
    count += 1
  if s == "2021/6/5" or s == "2021/6/4":
    print(s,count)

print(count)
