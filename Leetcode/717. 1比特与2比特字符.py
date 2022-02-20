"""
author: L
date: 2022/2/20 23:11
"""

class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = 0
        while(i < len(bits)):
            if bits[i] == 1:
                i += 2
            else:
                i += 1
                if i == len(bits):
                    return True
        return False
