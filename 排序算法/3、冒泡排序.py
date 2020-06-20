'''
冒泡排序：
时间复杂度:最佳O(n) 最差O(n^2) 平均O(n^2)
空间复杂度：O(1)
'''


def BubbleSort(nums):
    for i in range(len(nums)-1):
        for j in range(len(nums) - i-1):
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
    return nums


if __name__ == '__main__':
    nums = [1, 3, 9, 2, 8, 5, 6]
    print(BubbleSort(nums))
