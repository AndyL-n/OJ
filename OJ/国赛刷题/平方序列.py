import os
import sys

for x in range(2020,10000):
  for y in range(x,10000):
    if (2019 ** 2 + y**2 == x**2 *2):
      print(x,y,x+y)
