'''
插入排序
时间复杂度:最佳O(n) 最差O(n^2) 平均O(n^2)
空间复杂度：O(1)
算法原理：对于未排列序列，在已排序列中从后向前扫描到相应位置插入

'''


def InsertSort(nums):
    for i in range(1, len(nums)):
        current = nums[i]
        pre_index = i - 1
        while pre_index>=0 and nums[pre_index]>current:
            nums[pre_index+1]=nums[pre_index]
            pre_index-=1
        nums[pre_index+1]=current
    return nums


if __name__=='__main__':
    nums=[1,3,9,2,8,5,6]
    print(InsertSort(nums))
