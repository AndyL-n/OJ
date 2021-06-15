n = int(input())
for i in range(n):
  s1 = input()
  s2 = input()
  s3 = input()
  cntR, cntG, cntY = [0 for i in range(4)], [0 for i in range(4)], [0 for i in range(4)]
  for index,val in enumerate(s1):
    if val == 'G':
      cntG[index%4] += 1
    elif val == 'R':
      cntR[index%4] += 1
    elif val == 'Y':
      cntY[index%4] += 1
  for index,val in enumerate(s2):
    if val == 'G':
      cntG[index%4] += 1
    elif val == 'R':
      cntR[index%4] += 1
    elif val == 'Y':
      cntY[index%4] += 1
  for index,val in enumerate(s3):
    if val == 'G':
      cntG[index%4] += 1
    elif val == 'R':
      cntR[index%4] += 1
    elif val == 'Y':
      cntY[index%4] += 1
  flag = 1
  for j in range(4):
    if cntG[j] == 3 and cntR[j] == 2 and cntY[j] == 1:
      continue
    else:
      print("NO")
      flag = 0
      break
  if flag:
    print("YES")
