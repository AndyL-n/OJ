# import sys
# import os
#
# prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
# t = [0 for i in range(0,101)]
#
# for i in range(2,101):
#   for j in prime:
#     while i%j==0:
#       i=i/j
#       t[j]+=1
#
# ans = 1
# for i in prime:
#   ans *= (t[i] + 1)
# print(ans)

ans = 1
for i in range(1,101):
  ans *= i
print(ans)

t = 0
for i in range(1,ans+1):
  if ans % i == 0:
    t += 1
print(t)