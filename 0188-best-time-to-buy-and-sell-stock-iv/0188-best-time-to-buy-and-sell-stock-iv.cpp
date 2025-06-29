class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();


vector<vector<vector<int>>>dp(1,vector<vector<int>>(2,vector<int>(k+1,0)));

    for(int i=n-1; i>=0; i--)
    {
        for(int flag=0; flag<2; flag++)
        {
            for(int d=1; d<=k; d++)
            {
                if(flag>0)
                {

           int x=max(prices[i]+dp[0][0][d-1],dp[0][1][d]);
           dp[0][flag][d]=x;
                }
                else
                {
           int x=max(-prices[i]+dp[0][1][d],dp[0][0][d]);
            dp[0][flag][d]=x;
                }
            }
        }
    }
   return dp[0][0][k];
    }
};