class Solution(object):
    def movingCount(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        rows = m
        cols = n
        threshold = k
        array = []
        for i in range(rows):
            tmp = []
            for j in range(cols):
                tmp.append(getN(i, j))
            array.append(tmp)
        visited = [[0] * len(array[0]) for _ in range(len(array))]
        return BFS(array, 0, 0, threshold, visited)


def getN(i, j):
    res = 0
    while i:
        res += (i % 10)
        i //= 10
    while j:
        res += (j % 10)
        j //= 10
    return res


def BFS(array, i, j, threshold, visited):
    if i < 0 or j < 0 or i > len(array) - 1 or j > len(array[0]) - 1 or array[i][j] > threshold or visited[i][j]:
        return 0
    res = 1
    visited[i][j] = 1
    res += BFS(array, i + 1, j, threshold, visited)
    res += BFS(array, i - 1, j, threshold, visited)
    res += BFS(array, i, j + 1, threshold, visited)
    res += BFS(array, i, j - 1, threshold, visited)
    return res



if __name__ == '__main__':
    f = lambda x: x + 1
    print(f(4))
    a = Solution()
    res = a.movingCount(2, 3, 1)
    print(res)
