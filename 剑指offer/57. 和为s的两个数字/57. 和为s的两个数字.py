# 双指针


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i,j=0,len(nums)-1
        while nums[i]+nums[j]!=target:
            if nums[i]+nums[j]>target:
                j-=1
            else:
                i+=1
        return [nums[i],nums[j]]