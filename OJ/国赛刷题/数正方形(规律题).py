n = int(input())
ans = 0
mod = 10**9+7
for i in range(1,n+1):
  ans += i * (n-i)**2 % mod
  ans %= mod
print(ans % mod)
