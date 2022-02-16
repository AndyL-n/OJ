"""
author: L
date: 2022/1/12 21:43
"""

from sys import exit
t = int(input())

while(t):
    l = int(input())
    val = list(map(int, input('').split()))
    mindis = 150000
    dict = {}
    for index, i in enumerate(val):
        if dict.get(i) or dict.get(i) == 0:
            ans = index - dict.get(i)
            mindis = ans if mindis > ans else mindis
        dict[i] = index
    if mindis == 150000:
        print(-1)
    else:
        print(l - mindis)
    # exit()
    t -= 1