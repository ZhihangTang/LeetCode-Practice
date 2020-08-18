[7,1,5,3,6,4]


# 第一题基本情况（允许交易一次）
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)return 0;
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[0][1]=-prices[0];
        for(int i=1;i<=n;++i){
            dp[i][0]=max(dp[i-1][1]+prices[i-1],dp[i-1][0]);
            dp[i][1]=max(-prices[i-1],dp[i-1][1]);
        }
        return dp[n][0];    
    }
};

简化版
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)return 0;
        int dp_i_0=0,dp_i_1=-prices[0];
        for(int i=1;i<=n;++i){
            dp_i_0=max(dp_i_1+prices[i-1],dp_i_0);
            dp_i_1=max(-prices[i-1],dp_i_1);
        }
        return dp_i_0;
    }
};



# 第二题进行多次交易
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp_i_0=0;
        int dp_i_1=INT_MIN;
        for(int i=0;i<n;++i){
            int tmp=dp_i_0;
            dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
            dp_i_1=max(dp_i_1,tmp - prices[i]);
        }
        return dp_i_0;
    }
};

# 第三题最多2次交易
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2)));
        for(int i=0;i<n;++i){
            for(int k=2;k>=1;--k){
                if(i==0){
                    dp[i][k][0]=0;
                    dp[i][k][1]=-prices[i];
                    continue;
                }
                dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
            }
        }
        return dp[n-1][2][0];
    }
};

# 第四题最多进行k次交易
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;
        if(k>n/2) return maxProfit_k_inf(prices);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2)));
        for(int i=0;i<n;++i){
            for(int j=k;j>=1;--j){
                if(i==0){
                    dp[i][j][0]=0;
                    dp[i][j][1]=-prices[i];
                    continue;
                }
                dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i]);
                dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]);
            }
        }
        return dp[n-1][k][0];
    }
    int maxProfit_k_inf(vector<int>& prices){
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2));
        for(int i=0;i<n;++i){
            if(i==0){
                dp[i][0]=0;
                dp[i][1]=-prices[i];
                continue;
            }
            int tmp=dp[i-1][0];
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],tmp-prices[i]);
        }
        return dp[n-1][0];
    }
};

# 第五题最佳买卖股票时机含冷冻期
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp_i_0=0,dp_i_1=INT_MIN;
        int dp_pre_0=0;
        for(int i=0;i<prices.size();++i){
            int tmp=dp_i_0;
            dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
            dp_i_1=max(dp_i_1,dp_pre_0-prices[i]);
            dp_pre_0=tmp;
        }
        return dp_i_0;
    }
};

# 第六题买卖股票的最佳时机含手续费
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int dp_i_0=0,dp_i_1=INT_MIN;
        for(int i=0;i<n;++i){
            int tmp=dp_i_0;
            dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
            dp_i_1=max(dp_i_1, tmp-prices[i]-fee);
        }
        return dp_i_0;

    }
};