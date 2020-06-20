'''
快速排序:分治法
时间复杂度：平均O(nlogn)最坏n^2
步骤：从数列中跳出一个元素，成为pivot（基准）
2、重新排序数列，比基准值小的摆放在基准前面，比基准值大的放在后面
'''


def QuickSort(nums):
    if len(nums) < 2:
        return nums
    mid = nums[len(nums) // 2]
    left, right = [], []
    nums.remove(mid)
    for item in nums:
        if item >= mid:
            right.append(item)
        else:
            left.append(item)
    return QuickSort(left) + [mid] + QuickSort(right)

def sort0(nums):
    if len(nums) < 2:
        return nums
    mid = nums[len(nums) // 2]
    left, right = [], []
    nums.remove(mid)
    for item in nums:
        if item < mid:
            left.append(item)
        else:
            right.append(item)
    return sort0(left) + [mid] + sort0(right)

if __name__ == '__main__':
    nums = [1, 3, 9, 2, 8, 5, 6]
    print(sort0(nums))



