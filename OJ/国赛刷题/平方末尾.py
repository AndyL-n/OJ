import os
import sys

ans = []
for i in range(10,100):
  tmp = str(i*i)[len(str(i*i))-2:]
  if tmp not in ans:
    ans.append(tmp)
print(len(ans))
