class Solution {
public:

    int ans(vector<int> &prices,int n,int flag, vector<vector<int>> &dp)
    {
        //base case : 

        if(n==prices.size())
        {
            return 0;
        }

        if(dp[n][flag]!=-1) return dp[n][flag];

        if(flag==0)
        {
            int buy = -prices[n]+ans(prices,n+1,1,dp);
            int move = ans(prices,n+1,0,dp);
            return dp[n][flag]=max(buy,move);
        }
        else
        {
            int move = ans(prices,n+1,1,dp);
            int sold = prices[n]+ans(prices,n+1,0,dp);

            return dp[n][flag]=max(move,sold);
        }
        return -1;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return ans(prices,0,0,dp);
    }
};