'''
设dp[i]表示以元素nums[i]结尾的连续子数组的最大和

若dp[i-1]<=0,说明dp[i-1]对dp[i]产生负贡献，即dp[i-1]+nums[i]
还不如nums[i]本身大
当dp[i-1]>0时，执行dp[i]=dp[i-1]+nums[i]
当dp[i-1]<=0时，执行dp[i]=nums[i]
初始状态dp[i]=nums[0]

'''

def fun(nums):
    dp=[0 for _ in range(len(nums))]
    for i in range(1,len(nums)):
        dp[i]=max(nums[i],dp[i-1]+nums[i])
    return max(dp)


