# 预处理完全平方数+组合完全平方数(用[9:0]的状态代表25 用0000100100)
import os
import sys

max_number, ans, data, tmp = 9876543210, 0, [], []

def dfs(index,length):
  global tmp, ans, data
  # tmp.append(index)
  if (length == (1 << 10) - 1):
    # print(tmp)
    ans += 1
    # tmp.pop()
    return
  else:
    for i in range(index,len(data)):
      if data[i] & length == 0:
        dfs(i + 1, data[i]|length)
    # tmp.pop()
        
def fun():
  global data, max_number
  i = 0
  while i*i <= max_number + 1:
    number = i*i
    val,flag = 0, True
    while number > 0 and flag:
      if (val >> number%10) & 1 == 0:
        val |= 1 << number%10
      else:
        flag = False
        break
      number //= 10
    
    if flag:
      data.append(val)
    i += 1
    
if __name__=="__main__":
  fun()
  data[0] = 1
  dfs(0,0)
  print(ans)
