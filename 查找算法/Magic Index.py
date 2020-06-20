'''
有一个有意思的题目叫做Magic Index：给定一个数组A，其中有一个位置被称为Magic Index，
含义是：如果i是Magic Index，则A[i] = i。
假设A中的元素递增有序、且不重复，请给出方法，找到这个Magic Index。
更进一步，当A中允许有重复的元素，该怎么办呢？
用一个二分查找
'''

def findMagicIndex(A):
    def func(A,st,ed):
        if ed<st or st<0 or ed>len(A):
            return -1
        mid = (st + ed) // 2
        midVal=A[mid]
        if A[mid]==midVal:
            return  mid
        left_idx=min(mid-1,midVal)
        left=findMagicIndex(A,st,left_idx)
        if left>=0:
            return left
        right_idx=min(mid+1,ed)
        right=findMagicIndex(A)
        return right
    func(A,0,len(A)-1)

class Solution:
    def getLeftBound(self, a):
        low = 0
        high = len(a) - 1

        while low <= high:
            mid = (low + high) // 2
            if a[mid] == mid and (mid == 0 or a[mid - 1] != mid - 1):
                return mid
            elif a[mid] < mid:
                low = mid + 1
            elif a[mid] > mid:
                high = mid - 1
            else:
                high = mid - 1
        return -1

    def getRightBound(self, a):
        low = 0
        high = len(a) - 1

        while low <= high:
            mid = (low + high) // 2
            if a[mid] == mid and (mid == len(a) - 1 or a[mid + 1] != mid + 1):
                return mid
            elif a[mid] < mid:
                low = mid + 1
            elif a[mid] > mid:
                high = mid - 1
            else:
                low = mid + 1
        return -1
    def getAns(self, a):
        l = self.getLeftBound(a)
        r = self.getRightBound(a)
        return a[l : r + 1]
s = Solution()
a = [-1, 2, 2, 3, 4, 5, 6, 9]

print(s.getAns(a))
