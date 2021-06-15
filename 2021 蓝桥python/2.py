ans = 0

# n = 20210605 +1
primes = []
n = 20210605+1

for i in range(2,n):
  flag = 0
  for j in str(i):
    if j in ['2','3','5','7']:
      continue
    else:
      flag = 1
      break
  if flag == 0:
    ans += 1
    primes.append(i)
ans = 0
for i in primes:

  flag = 1
  for j in range(2,i):
    if i % j == 0:
      flag = 0
      break
##  print(i,flag)
  if flag:
    ans += 1
print(ans)
