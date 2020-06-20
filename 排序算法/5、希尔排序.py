'''
希尔排序：
         1959年Shell发明，第一个突破O(n2)的排序算法，
         是简单插入排序的改进版。它与插入排序的不同之处在于，
         它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。

'''

def shell_sort(alist):
    """希尔排序"""
    n = len(alist)
    gap = n // 2
    while gap >= 1:
        for j in range(gap, n):
            i = j
            while (i - gap) >= 0:
                if alist[i] < alist[i - gap]:
                    alist[i], alist[i - gap] = alist[i - gap], alist[i]
                    i -= gap
                else:
                    break
        gap //= 2


if __name__ == '__main__':
    alist = [54, 26, 93, 17, 77, 31, 44, 55, 20]
    print("原列表为：%s" % alist)
    shell_sort(alist)
    print("新列表为：%s" % alist)

