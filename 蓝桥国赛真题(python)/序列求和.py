flag = [0 for _ in range(65)]
val = [0 for _ in range(65)]
for i in range(1,100000000):
  count = 0
  for j in range(1,i+1):
    if i % j == 0:
      count += 1
  if count > 60:
    continue
  if not flag[count]:
    flag[count] = 0
    val[count] = i
  if flag[1:61].count(1) == 60:
    break
print(val)

