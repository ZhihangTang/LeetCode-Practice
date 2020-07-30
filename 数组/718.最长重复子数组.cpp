/*
718. 最长重复子数组
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例 1:

输入:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出: 3
解释:
长度最长的公共子数组是 [3, 2, 1]。
dp[i][j]
0 0 1 0 0
0 1 0 0 0
1 0 0 0 0
0 2 0 0 0
0 0 3 0 0
*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size(),n=B.size();
        if(m==0 || n==0) return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //dp[i][j]表示的是A[i-1]与B[j-1]结尾的公共字串的长度,
        int res=0;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(A[i-1]==B[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    res=max(res,dp[i][j]);
                }
            }
        }
        return res;
    }
};


