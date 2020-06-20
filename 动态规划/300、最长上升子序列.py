
'''
dp[i]表示0-i的最长上升子序列长度
从小到大计算dp[]数组的值，在计算dp[i]之前，我们已经计算出dp[0,..i-1]
则有dp[i]=max(dp[i],dp[j]+1)



'''
from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp=[]
        for i in range(len(nums)):
            dp.append(1)
            for j in range(i):
                if nums[i]>nums[j]:
                    dp[i]=max(dp[i],dp[j]+1)
        return max(dp)


