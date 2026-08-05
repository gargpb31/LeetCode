class Solution {
public:
    int ways(int n,int x,vector<int> &dp)
    {
        if(x>n) return 0;
        if(x==n) return 1;

        if(dp[x]!=-1) return dp[x];
        return dp[x]=(ways(n,x+1,dp)+ways(n,x+2,dp));
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans = ways(n,0,dp);
        return ans;
    }
};