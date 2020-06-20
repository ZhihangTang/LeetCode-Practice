'''
64. 最小路径和
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
'''
from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # 当机器人从左上角走到(i, j) 这个位置时，最下的路径和是 dp[i] [j]。
        # 那么，dp[m-1] [n-1] 就是我们要的答案了。
        m, n = len(grid), len(grid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        # 初始化
        tmp = 0
        for i in range(n):
            tmp += grid[0][i]
            dp[0][i] = tmp
        tmp = 0
        for i in range(m):
            tmp += grid[i][0]
            dp[i][0] = tmp
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j])
        return dp[m - 1][n - 1]

