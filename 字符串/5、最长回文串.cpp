5. 最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

动态规划思路：
dp[i][j]表示 s[i][j]是否为回文串
转移情况：如果s[i]!=s[j] dp[i][j]=0
         如果s[i]==s[j],
         则分为1、j-i<=2 肯定为回文串，
         否则dp[i][j]=dp[i+1][j-1]

     for(int i=1；i<n;++i){
        for(int j=0;j<i;++j){
            转移方程
        }
     }

class Solution {
public:
	string longestPalindrome(string s) {
		int m = s.length();
		if (m <= 1) return s;
		string max_s = s.substr(0, 1);
		int max_len = 1, cur_len = 0;
		vector<vector<int>> dp(m, vector<int>(m, 0));
		for (int i = 1; i < m; ++i) {
			for (int j = 0; j < i; ++j) {
				if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1] == 1)) {
                    //左右相等且长度小于等于2或内部为回文，则[i,j]为回文
					dp[j][i] = 1;
					cur_len = i - j + 1;
				}
				if (cur_len > max_len)
				{
					max_len = cur_len;
					max_s = s.substr(j, max_len);
				}
			}

		}
		return max_s;
	}
};