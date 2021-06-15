##primes = []
##
##n = 1000
def fun(n):
 global primes
 flag = [0 for i in range(0,n+1)]
 for i in range(2,n+1):
   if flag[i] == 0:
     primes.append(i)
   for prime in primes:
     if i*prime > n:
       break;
     flag[i*prime] = 1
     if i % prime == 0:
       break
##  print(len(primes))
##fun(n)
##dp = [0 for i in range(0,n+1)]
##dp[0] = 1
##
##for i in primes:
##  j = n
##  while (j >= i):
##    dp[j] += dp[j-i]
##    j -= 1
##
##print(dp[n])
primes = [1,2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277]
ans = 1
for i in primes:
  ans *= i
print(ans)
