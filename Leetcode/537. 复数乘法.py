"""
author: L
date: 2022/2/25 12:38
"""

class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        # x1, y1 = num1.split('+')
        # x2, y2 = num2.split('+')
        # x1, x2 = int(x1), int(x2)
        # y1, y2 = int(y1[:-1]), int(y2[:-1])
        # x = x1*x2 - y1*y2
        # y = x1*y2 + x2*y1
        # return str(x) + '+' + str(y) + 'i'

        x1, y1 = map(int, num1[:-1].split('+'))
        x2, y2 = map(int, num2[:-1].split('+'))
        return str(x1*x2 - y1*y2) + '+' + str(x1*y2 + x2*y1) + 'i'

