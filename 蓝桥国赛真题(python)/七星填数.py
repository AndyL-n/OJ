import os
import sys
import itertools

for i in itertools.permutations([1,2,3,4,5,7,8,9,10,12,13]):
  num = i[0]+i[1]+i[2]+i[3]
  if num == 6+i[1]+i[4]+14 and num == 6+i[2]+i[5]+11 and num == 14+i[6]+i[7]+i[9] and num == i[3]+i[5]+i[8]+i[9] and num == i[10]+i[7]+i[8]+11 and num == i[0]+i[4]+i[6]+i[10]:
    print(i[0],i[1],i[2],i[3])
    break

