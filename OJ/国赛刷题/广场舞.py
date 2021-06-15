import os
import sys

length = int(input())

data = [None for i in range(length)]
i = 0
while i < length:
  data[i] = []
  data[i].append(list(map(int,input().split(' '))))
  if i != 0:
    data[i-1].append(data[i][0])
  i += 1
data[length-1].append(data[0][0])

