"""
author: L
date: 2022/2/24 15:35
"""

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # return True if re.compile(p).fullmatch(s) else False
        m, n = len(s), len(p)
        f = [[False] * (n + 1) for _ in range(m + 1)]
        f[0][0] = True
        for i in range(m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '*':
                    f[i][j] |= f[i][j - 2]
                    if False if i == 0 else (True if p[j - 2] == '.' else s[i - 1] == p[j - 2]):
                        f[i][j] |= f[i - 1][j]
                else:
                    if False if i == 0 else (True if p[j - 1] == '.' else s[i - 1] == p[j - 1]):
                        f[i][j] |= f[i - 1][j - 1]
        return f[m][n]
