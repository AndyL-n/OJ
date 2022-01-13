"""
author: L
date: 2022/1/12 20:45
"""
from sys import exit
t = int(input())

while(t):
    n, l = map(int, input().split())
    # print(n, l)
    val = list(map(int, input('').split()))
    length = len(bin(max(val))) - 2
    # print(length)
    val = ['{:030b}'.format(i) for i in val]
    ans = ''
    for i in range(30 - length, 30):
        a, b = 0, 0
        for j in val:
            if j[i] == '0':
                a += 1
            else:
                b += 1
        # print(a,b)
        if a >= b:
            ans += '0'
        else:
            ans += '1'
        # print(ans)
    print(int(ans,2))
    # exit()
    t -= 1