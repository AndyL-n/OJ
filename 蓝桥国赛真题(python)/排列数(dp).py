import os
import sys
import itertools

if __name__ == '__main__':
  mod = 123456
  n,k = map(int,input().split())
  dp = [[0 for _ in range(k+5)] for _ in range(n+5)]
  dp[1][0]
  for i in range(2,n+1):
    dp[i][0] = 2
    for j in range(0,i-1):
      dp[i + 1][j] = (dp[i + 1][j] + (dp[i][j] * (j + 1)) % mod) % mod
      dp[i + 1][j + 1] = (dp[i + 1][j + 1] + (dp[i][j] * 2) % mod) % mod
      dp[i + 1][j + 2] = (dp[i + 1][j + 2] + (dp[i][j] * (i - j - 2)) % mod) % mod
  ans = dp[n][k-1]%mod
  print(ans)


n, m = map(int, input().split())
nums = []
count = 0
for i in range(1, n + 1):
    nums.append(i)
for num in itertools.permutations(nums):
    temp = 0
    for i in range(n - 2):
        if num[i + 1] > num[i + 2] and num[i + 1] > num[i]:
            temp += 1
        elif num[i + 1] < num[i + 2] and num[i + 1] < num[i]:
            temp += 1
    if temp == m - 1:
        count += 1
count %= 123456
print(count)
