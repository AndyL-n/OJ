"""
author: L
date: 2022/3/2 15:03
"""

class Solution:
    def nearestPalindromic(self, n: str) -> str:
        # 对于任意一个数，如12345，其最近的回文数只会从以下五种中得到：
        # 将前一半填入后一半：12321
        # 将前一半加一填入后一半：12421
        # 将前一半减一填入后一半：12221
        # 下边界：9999
        # 上边界：100001
        # 从这五个数里面选取不等于原数的，且与原数差距最小的最小的数即为答案。

        length = len(n)
        if length < 2:
            return str(int(n)-1)


        candidates = []
        l,r = 10**(length - 1 ) - 1, 10**(length) + 1
        candidates.append(l)
        # 奇数
        if length & 1:
            tmp = list(n)
            tmp[length//2:] = tmp[length//2::-1]
            tmp = int(''.join(tmp))
            mid = 10**(length//2)
            candidates.extend([tmp - mid,tmp, tmp + mid])
        else:
            tmp = list(n)
            tmp[length//2:] = tmp[length//2-1::-1]
            tmp = int(''.join(tmp))
            mid = 10**(length//2) + 10**(length//2 - 1)
            candidates.extend([tmp - mid,tmp, tmp + mid])
        candidates.append(r)
        length = 10**18-1
        ans = 0
        print(candidates)
        for candidate in candidates:
            if str(candidate) == str(candidate)[::-1] and candidate != int(n) and abs(candidate - int(n)) < length:
                length = abs(candidate - int(n))
                ans = candidate
        return str(ans)

