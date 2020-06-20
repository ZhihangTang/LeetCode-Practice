'''
选择排序
时间复杂度：O(n^2)
空间复杂度：O(1)
不稳定
工作原理：首先在未排序序列中找到最小（大）元素，
存放到排序序列的起始位置，然后，再从剩余未排序
元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
'''


def SelectSort(list1):
    for i in range(len(list1)):
        # 每一次循环把当前未排序最小值放到list1[i]
        for j in range(i, len(list1)):
            if list1[i] > list1[j]:
                list1[i], list1[j] = list1[j], list1[i]
    return list1


list1 = [4, 1, 3, 7, 5, 9, 6, 2]
print(SelectSort(list1))
