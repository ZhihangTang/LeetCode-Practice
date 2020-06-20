'''

560. 和为K的子数组
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
具体算法：

维护一个 hashmap，hashmap 的 key 为累加值 acc，value 为累加值 acc 出现的次数。
迭代数组，然后不断更新 acc 和 hashmap，如果 acc 等于 k，那么很明显应该+1. 如果 hashmap[acc - k] 存在，我们就把它加到结果中去即可。

作者：fe-lucifer
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/qian-zhui-he-si-xiang-560-he-wei-kde-zi-shu-zu-by-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。\
'''
from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        d = {}
        acc = count = 0
        for num in nums:
            acc += num
            if acc == k:        # 如果当前和等于k，count+1
                count += 1
            if acc - k in d:    # 如果当前和-k在d中，count+d[acc-k]
                count += d[acc - k]
            if acc in d:        # 如果acc已经存在，加yi
                d[acc] += 1
            else:
                d[acc] = 1
        return count
