class Solution {
public:

//     int ans(vector<int> &prices, int n, int d, int flag,vector<vector<vector<int>>> &dp)
//     {
//             if(d==0) return 0;
//             if(n==prices.size()) return 0;
//         if(dp[n][flag][d]!=-1) return dp[n][flag][d];
//             if(flag>0)
//             {
// return dp[n][flag][d]=max(prices[n]+ans(prices,n+1,d-1,0,dp),ans(prices,n+1,d,1,dp));
//             }

//         return dp[n][flag][d]=max(-prices[n]+ans(prices,n+1,d,1,dp),ans(prices,n+1,d,0,dp));
        
//     }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();


vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

    for(int i=n-1; i>=0; i--)
    {
        for(int flag=0; flag<2; flag++)
        {
            for(int d=1; d<3; d++)
            {
                if(flag>0)
                {
            dp[i][flag][d]=max(prices[i]+dp[i+1][0][d-1],dp[i+1][1][d]);
                }
                else
                {
            dp[i][flag][d]=max(-prices[i]+dp[i+1][1][d],dp[i+1][0][d]);
                }
            }
        }
    }
    int ans = 0;
    for(int flag=0; flag<2; flag++)
    {
        for(int d=1; d<=2; d++)
        {
                ans=max(ans,dp[0][flag][d]);
        }
    }
    return ans;

    }
};