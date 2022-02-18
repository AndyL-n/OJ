"""
author: L
date: 2022/2/16 15:50
"""

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        ans = [0 for _ in range(len(num1) + len(num2))]

        for i in range(len(num1)):
            for j in range(len(num2)):
                ans[i + j] += (ord(num1[len(num1) - i - 1]) - ord('0')) * (ord(num2[len(num2) - j - 1]) - ord('0'))

        for i,val in enumerate(ans):
            val = ans[i]
            ans[i] = val % 10
            if i + 1 == len(ans):
                break
            ans[i + 1] += int((val - ans[i]) / 10)

        ans = ''.join(str(i) for i in ans[::-1])
        for i,val in enumerate(ans):
            if val == '0':
                if i == len(ans) - 1:
                    ans = "0"
                    break
                continue
            else:
                ans = ans[i:]
                break
        return ans



if __name__ == '__main__':

    num1, num2 = "123","456"
    a = Solution()
    print(a.multiply(num1,num2))
