/*
'''
120. 三角形最小路径和
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。



例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
'''
解题思路和其他最短路径思路差不多
定义一个dp[m][n]
dp[i][j]表示从原点到点[i,j]的最小路径和


*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        if(m==1) return triangle[0][0];
        int n=triangle[m-1].size();
        int res=INT_MAX;
        vector<vector<int>> dp(m,vector<int>(n,0));
         //base case
        dp[0][0]=triangle[0][0];
        for(int i=1;i<m;++i){
            for(int j=0;j<triangle[i].size();++j){
                //边界情况
                if(j==0){
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                    continue;
                }
                if(j==triangle[i].size()-1){
                    dp[i][j]=dp[i-1][j-1]+triangle[i][j];
                }
                //转移方程
                else dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }
        }
        for(int i=0;i<dp[m-1].size();++i){
            res=min(res,dp[m-1][i]);
        }
        return res;
    }
};
