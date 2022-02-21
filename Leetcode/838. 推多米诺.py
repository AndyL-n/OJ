"""
author: L
date: 2022/2/21 21:23
"""

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        s = list(dominoes)
        i = 0
        left = 'L'
        while i < len(s):
            j = i
            while j < len(s) and s[j] == '.':  # 找到一段连续的没有被推动的骨牌
                j += 1
            right = s[j] if j < len(s) else 'R'
            if left == right:  # 方向相同，那么这些竖立骨牌也会倒向同一方向
                while i < j:
                    s[i] = right
                    i += 1
            elif left == 'R' and right == 'L':  # 方向相对，那么就从两侧向中间倒
                k = j - 1
                while i < k:
                    s[i] = 'R'
                    s[k] = 'L'
                    i += 1
                    k -= 1
            left = right
            i = j + 1
        return ''.join(s)