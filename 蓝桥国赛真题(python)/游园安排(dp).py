import sys
import os

def binary_search(R, x):
##二分查找，返回a数组中第一个>=x的位置
  global dp
##  if x == "J":
##    print("------")
##    print(dp)
  L = 0
  while(L <= R):
    mid = (L+R) >> 1;
    if dp[mid] == x:
      return mid
    elif(dp[mid] < x):
        L = mid + 1;
    else :
        R = mid - 1;
##    if x == "J":
##      print(L,R,mid)
##  if x == "J":
##    print("------")
  return L;


s = input()
name = []
tmp = ""
count = 0
for i in s:
  if ord(i) in range(65, 91):
    if tmp != "":
      name.append(tmp)
    tmp = i
  else:
    tmp += i
name.append(tmp)

n = len(name)
dp, pos = ["" for i in range(n)], [0 for i in range(n)]

length = 0
dp[length] = name[0]
pos[length] = 1
for i in range(1,n):
  if (dp[length] < name[i]):
    length += 1
    dp[length] = name[i]
    pos[i] = length + 1
  else:
    j = binary_search(length,name[i])
    dp[j] = name[i]
    pos[i] = j+1


##for i in pos:
##  print(i,end=" ")
length = max(pos)
##print(length)
ans = []
for i in range(len(pos) - 1,-1,-1):
  if pos[i] == length:
    ans.append(name[i])
    length -= 1

for i in range(len(ans)-1,-1,-1):
  print(ans[i],end='')
    
  
