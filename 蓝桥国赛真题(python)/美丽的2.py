import os
import sys

##count = 0
##for i in range(1,2021):
##  if str(i).count('2'):
##    count += 1
print(len([ str(i) for i in range(2,2021)if '2'  in str(i)]))
