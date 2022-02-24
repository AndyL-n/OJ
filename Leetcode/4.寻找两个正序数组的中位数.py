"""
author: L
date: 2022/2/24 15:28
"""


class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        m, n = len(nums1), len(nums2)
        if m > n:
            return self.findMedianSortedArrays(nums2, nums1)

        iMin, iMax = 0, m;
        while (iMin <= iMax):
            i = int((iMin + iMax) / 2)
            j = int((m + n + 1) / 2 - i)
            if j != 0 and i != m and nums2[j - 1] > nums1[i]:  # i 需要增大
                iMin = i + 1
            elif i != 0 and j != n and nums1[i - 1] > nums2[j]:  # i 需要减小
                iMax = i - 1
            else:  # 达到要求，并且将边界条件列出来单独考虑
                maxLeft, minRight = 0, 0
                if i == 0:
                    maxLeft = nums2[j - 1]
                elif j == 0:
                    maxLeft = nums1[i - 1]
                else:
                    maxLeft = max(nums1[i - 1], nums2[j - 1])

                if (m + n) & 1:  # 奇数的话不需要考虑右半部分
                    return maxLeft

                if i == m:
                    minRight = nums2[j]
                elif j == n:
                    minRight = nums1[i]
                else:
                    minRight = min(nums2[j], nums1[i])

                return (maxLeft + minRight) / 2.0;  # 如果是偶数的话返回结果
        return 0.0
