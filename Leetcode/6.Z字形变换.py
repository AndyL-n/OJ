"""
author: L
date: 2022/2/16 21:31
"""

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        ans = [[] for _ in range(numRows)]
        index = 0
        row = 0
        flag = 1 # 1向下 0向上
        while(index < len(s)):
            ans[row].append(s[index])
            if row == 0:
                flag = 1
            elif row == numRows - 1:
                flag = 0
            if flag:
                row += 1
            else:
                row -= 1
            index += 1

        d = ""
        for val in ans:
            for i in val:
                d += i
        return d
    