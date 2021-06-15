import os
import sys

# 请在此输入您的代码
for i in range(1,100,2):
  val = 2019 * i
  flag = 1
  while(val > 0 and flag):
    if val % 10 & 1:
      val //= 10
    else:
      flag = 0
  if flag:
    break
print(i*2019)
