'''
给你一个树，请你按中序遍历重新排列树，
使树中最左边的结点现在是树的根，
并且每个结点没有左子结点，只有一个右子结点。


'''


def addBinary(a: str, b: str) -> str:
    if len(a) < len(b):
        tmp = a
        a = b
        b = tmp
    m = len(a)
    n = len(b)
    t = 0
    res = ""
    for i in range(n):
        res = str((int(a[m -1- i]) + int(b[n - 1 - i]) + t) % 2)+res
        t = (int(a[m - 1 - i]) + int(b[n - 1 - i]) + t) // 2
    for i in range(n, m):
        res = str((int(a[m - 1 - i]) + t) % 2)+res
        t = (int(a[m -1- i]) + t) // 2
    if t != 0:
        res = str(t) + res
    return res

a="100"
b="110010"
print(addBinary(a,b))