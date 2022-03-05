"""
author: L
date: 2022/3/5 20:35
"""

class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        return max(len(a), len(b)) if a != b else -1