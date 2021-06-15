import os
import sys
import itertools


numbers = [1,2,3,4,5,6,7,8,9]
ans = 0
for number in itertools.permutations(numbers):
    counts = set()
    counts.add(number[0] + number[1] + number[2])
    counts.add(number[3] + number[4] + number[5])
    counts.add(number[6] + number[7] + number[8])
    counts.add(number[0] + number[3] + number[6])
    counts.add(number[1] + number[4] + number[7])
    counts.add(number[2] + number[5] + number[8])
    counts.add(number[0] + number[4] + number[8])
    counts.add(number[2] + number[4] + number[6])
    if len(counts) == 8:
        ans += 1
    counts.clear()
print(int(ans / 8))
