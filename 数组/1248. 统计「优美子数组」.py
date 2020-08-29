'''
思路
双指针，当维护的区间中的奇数个数cnt达到k时，
保存此位置为k_cnt_right_begink_cnt_right_begin，
然后再将右端点r往右移直到指针到数组边界或右边的数字是个奇数（会导致cnt加1）。
此时移动左端点l，每次移动对答案的贡献是r - k_cnt_right_begin + 1 ，
即左端点为l，右端点落在[k_cnt_right_begin, r]的区间。
移动l并更新cnt直到cnt < k。此时再移动右指针。重复以上步骤直到遍历完数组即可。

时间复杂度 O(N) ，空间复杂度 O(1) 。

'''

class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        l, r, cnt, ans = 0, -1, 0, 0
        while r + 1 < len(nums):
            while r + 1 < len(nums) and cnt < k:
                r += 1
                cnt += nums[r] & 1
            if r >= len(nums):
                break
            k_cnt_right_begin = r
            while r + 1 < len(nums) and not nums[r + 1] & 1:
                r += 1
            while l <= r and cnt == k:
                ans += r - k_cnt_right_begin + 1
                cnt -= nums[l] & 1
                l += 1
        return ans
