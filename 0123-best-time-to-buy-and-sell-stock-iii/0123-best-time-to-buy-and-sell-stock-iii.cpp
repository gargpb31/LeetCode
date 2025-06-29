class Solution {
public:

    int ans(vector<int> &prices, int n, int d, int flag,vector<vector<vector<int>>> &dp)
    {
            if(d==0) return 0;
            if(n==prices.size()) return 0;
        if(dp[n][flag][d]!=-1) return dp[n][flag][d];
            if(flag>0)
            {
return dp[n][flag][d]=max(prices[n]+ans(prices,n+1,d-1,0,dp),ans(prices,n+1,d,1,dp));
            }

        return dp[n][flag][d]=max(-prices[n]+ans(prices,n+1,d,1,dp),ans(prices,n+1,d,0,dp));
        
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();


vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

    return ans(prices,0,2,0,dp);

    }
};