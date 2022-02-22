"""
author: L
date: 2022/2/22 15:13
"""


class Solution:
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        mod = 10 ** 9 + 7
        frequency = Counter(nums)

        f = [0] * (1 << len(primes))
        f[0] = pow(2, frequency[1], mod)

        for i, occ in frequency.items():
            if i == 1:
                continue

            # 检查 i 的每个质因数是否均不超过 1 个
            subset, x = 0, i
            check = True
            for j, prime in enumerate(primes):
                if x % (prime * prime) == 0:
                    check = False
                    break
                if x % prime == 0:
                    subset |= (1 << j)

            if not check:
                continue

            # 动态规划
            for mask in range((1 << len(primes)) - 1, 0, -1):
                if (mask & subset) == subset:
                    f[mask] = (f[mask] + f[mask ^ subset] * occ) % mod

        ans = sum(f[1:]) % mod
        return ans

