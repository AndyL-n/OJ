import os
import sys

distance, ans,flag = 1000, 0, 0 
while distance > 1:
    distance *= (2/3)
    flag ^= 1
    if flag:
      ans += 1
print(ans)
