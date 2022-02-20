"""
author: L
date: 2022/2/18 21:41
"""
# zip
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ""
        for index, tmp in enumerate(zip(*strs)):
            tmp = set(tmp)
            if len(tmp) == 1:
                ans += strs[0][index]
            else:
                break
        return ans
# 字典序
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        strs.sort()
        a, b = strs[0], strs[len(strs) - 1]
        index, flag = 0, 1
        for index in range(len(a)):
            if index < len(b) and a[index] == b[index]:
                continue
            else:
                flag = 0
                break
        return a if flag else a[:index]/
# 同位置比较
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]
        ans = 0
        minlen = min([len(i) for i in strs])
        print(minlen)
        while (1):
            if ans >= minlen:
                break
            flag = 1
            for i in strs:
                print(ans)
                if flag and i[ans] == strs[0][ans]:
                    continue
                else:
                    flag = 0
                    break
            if flag:
                ans += 1
            else:
                break

        return strs[0][:ans]