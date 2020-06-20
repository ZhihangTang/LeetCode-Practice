/*
给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。

 

示例 1：

输入：matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
输出：15
解释：
边长为 1 的正方形有 10 个。
边长为 2 的正方形有 4 个。
边长为 3 的正方形有 1 个。
正方形的总数 = 10 + 4 + 1 = 15.
示例 2：

输入：matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
输出：7
解释：
边长为 1 的正方形有 6 个。
边长为 2 的正方形有 1 个。
正方形的总数 = 6 + 1 = 7.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0 || n==0) return 0;
        int res=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i==0||j==0){
                    dp[i+1][j+1]=matrix[i][j]==1;
                }
                else{
                    if(matrix[i][j]==1){
                        dp[i+1][j+1]=min(min(dp[i+1][j],dp[i][j+1]),dp[i][j])+1;
                    }
                    else dp[i+1][j+1]=0;
                }
                res+=dp[i+1][j+1];
            }
        }
        return res;
    }
};

//  求一个dp，dp[i][j]表示 matrix[i][j]这个点可以往左上构造的最大正方形的边长，然后求和就行了