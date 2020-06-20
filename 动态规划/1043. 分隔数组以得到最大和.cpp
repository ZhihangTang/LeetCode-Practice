1043. 分隔数组以得到最大和
给出整数数组 A，将该数组分隔为长度最多为 K 的几个（连续）子数组。分隔完成后，每个子数组的中的值都会变为该子数组中的最大值。

返回给定数组完成分隔后的最大和。

 

示例：

输入：A = [1,15,7,9,2,5,10], K = 3
输出：84
解释：A 变为 [15,15,15,9,10,10,10]


思路:dp
dp[i]表示A[0:i]的分组最大和
base case: dp[0]=0
状态转移： dp[i] = max( dp[j] + max(A[j:i]) * (i - j) )，
            其中i - K <= j <= i - 1


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        //dp[i]表示以[0:i]的最大和
        int n=A.size();
        vector<int> dp(n+1,0);
        dp[1]=A[0];
        //dp[n]为所求
        for(int i=1;i<=n;++i){
            int maxn=-1;
            for(int j = i - 1; j >= max(i - K, 0); --j) { // 上一个结尾（同时逆序找最大值）
                maxn=max(maxn,A[j]);
                dp[i] = max(dp[i], dp[j] + maxn * (i - j));
            }
        }
        return dp[n];

    }
};


