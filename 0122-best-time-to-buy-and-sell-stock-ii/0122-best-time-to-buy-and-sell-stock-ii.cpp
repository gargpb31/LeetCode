class Solution {
public:
    int ans(vector<int> &p, int k, int cur, int n,vector<vector<int>> &dp)
    {
        if(cur==n)
        {
            if(k==1) return p[cur];
            return 0;
        }
        if(dp[cur][k]!=-1) return dp[cur][k];
        int ans1 = 0;
        if(k==0)
        {
            int take = ans(p,1,cur+1,n,dp)-p[cur];
            int ntake = ans(p,0,cur+1,n,dp);
            ans1=max(take,ntake);
        }
        else
        {
            int take = p[cur]+ans(p,0,cur+1,n,dp);
            int ntake = ans(p,1,cur+1,n,dp);
            ans1=max(take,ntake);
        }
        return dp[cur][k]=ans1;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return ans(prices,0,0,n-1,dp);
    }
};