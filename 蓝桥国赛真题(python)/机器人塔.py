import os
import sys
from math import sqrt, floor
n,m,num,ans = 0,0,0,0

def check(val,num):
    num_a, num_b = 0, 0
    for i in range(num,0,-1):
        num_b += bin(val)[2:].count('1')
        num_a += i - bin(val)[2:].count('1')
        val ^= val >> 1
        val &= (1 << (i - 1)) - 1
    return num_a == n and num_b == m

if __name__ == '__main__':
    n,m = map(int,input().split())
    num = floor(sqrt((n + m) * 2))
    for i in range(0, 1 << num):
        if check(i,num):
            ans += 1
    print(ans)
