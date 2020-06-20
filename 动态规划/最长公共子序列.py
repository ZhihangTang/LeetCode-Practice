'''
最长公共子序列（Longest Common Subsequence，简称 LCS）是一道非常经典的面试题目，因为它的解法是典型的二维动态规划，大部分比较困难的字符串问题都和这个问题一个套路，比如说编辑距离。而且，这个算法稍加改造就可以用于解决其他问题，所以说 LCS 算法是值得掌握的。

题目就是让我们求两个字符串的 LCS 长度：

输入: str1 = "abcde", str2 = "ace"
输出: 3
解释: 最长公共子序列是 "ace"，它的长度是 3

dp[i][j] 的含义是：对于 s1[1..i] 和 s2[1..j]，它们的 LCS 长度是 dp[i][j]。

比如上图的例子，d[2][4] 的含义就是：对于 "ac" 和 "babc"，它们的 LCS 长度是 2。我们最终想得到的答案应该是 dp[3][6]。
'''

#暴力
def LongestCommonSubsequence(str1, str2) -> int:
    def dp(i, j):
        # 空串的base case、
        if i == -1 or j == -1:
            return 0
        if str1[1] == str2[j]:
            # 这边找到一个lcs的元素，继续往前找
            return dp(i - 1, j - 1) + 1
        else:
            return max(dp(i - 1, j), dp(i, j - 1))

    return dp(len(str1) - 1, len(str2) - 1)


def longestCommonSubsequence2(str1, str2) -> int:
    m, n = len(str1), len(str2)
    # 构建 DP table 和 base case
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    # dp[i][j] 表示str1[0:i]和str2[0:j]的LCS长度
    # 进行状态转移
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            # 如果当前两个字符串中的值相等
            # 则
            if str1[i - 1] == str2[j - 1]:
                # 找到一个 lcs 中的字符
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[-1][-1]