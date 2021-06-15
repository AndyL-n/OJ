s = input()
t = input()
dp = [[1000 for i in range(len(t)+1)] for i in range(len(s)+1)]
dp[0][0] = 0
for i in range(0,len(s)):
  dp[i+1][0] = 0
  for j in range(0,len(t)):
    dp[i+1][j+1] = dp[i][j] if s[i] == t[j] else min(dp[i][j+1],dp[i][j]+1)
print(dp[len(s)][len(t)])
