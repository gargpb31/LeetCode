class Solution {
public:
    int ans(vector<vector<int>> &dp, int cur,int n,vector<int> &prices,int fee,int k)
    {
        if(cur==n) return 0;
        if(dp[cur][k]!=-1) return dp[cur][k];

        int profit = 0;
        if(k==0)
        {
            profit=max(ans(dp,cur+1,n,prices,fee,k),-prices[cur]+ans(dp,cur+1,n,prices,fee,1));
        }
        else
        {
            profit=max(ans(dp,cur+1,n,prices,fee,k),prices[cur]-fee+ans(dp,cur+1,n,prices,fee,0));
        }
        return dp[cur][k]=profit;
    }


    int maxProfit(vector<int>& prices, int fee) {

            int n = prices.size();
            vector<vector<int>> dp(n,vector<int>(2,-1));

            return ans(dp,0,n,prices,fee,0);
    }
};