'''
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"

动态规划方法：1、定义状态  2、找到状态转移方程
1、dp=[][]是否回文串的状态矩阵
2、
    a、当子串中只有一个字符，一定是回文串
    b、当子串中含有2个以上字符，如果s[l,r]回文，则s[l+1,r-1]一定回文
       当s[l]=s[r]时,d[l,r]的值由dp[l-1,r+1]决定，
       当边界字符串相等时，整个字符串是否回文由原字符串去掉左边边界后的子串是否回文解决

    c、还需要考虑

'''


def longestPalindrome(s):
    m = len(s)
    if m == 1:
        return s
    dp = [[0 for i in range(m + 1)] for i in range(m + 1)]
    max_l = 1
    cur_l = 1
    max_s = s[0:1]
    for i in range(1, m):
        for j in range(0, i):
            if s[i] == s[j] and (j - i < 2 or dp[i + 1][j - 1] == 1):
                dp[i][j] = 1
                cur_l = j - i + 1
            if cur_l > max_l:
                max_l = cur_l
                max_s = s[i:j + 1]
    return max_s
