class Solution {
public:

    int ans(vector<int> &prices, int n, int flag, vector<vector<int>>&dp)
    {
        if(n>=prices.size()) return 0;

        if(dp[n][flag]!=-1) return dp[n][flag];

        if(flag>0)
        {
return dp[n][flag]=max(prices[n]+ans(prices,n+2,0,dp),ans(prices,n+1,1,dp));

        } 
    return dp[n][flag]=max(-prices[n]+ans(prices,n+1,1,dp),ans(prices,n+1,0,dp));
    }

    int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> dp(n,vector<int>(2,-1));

    return ans(prices,0,0,dp);

    }
};