class Solution {
public:

    // int ways(vector<int> &dp,int pos,int n)
    // {
    //     if(pos==n) return 1;
    //     if(pos>n) return 0;

    //     if(dp[pos]!=-1) return dp[pos];

    //     int totways = ways(dp,pos+1,n)+ways(dp,pos+2,n);
    //     return dp[pos]=totways;
    // }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);

        dp[0]=1;
        dp[1]=1;
      

        for(int i=2; i<=n; i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

       
    }
};