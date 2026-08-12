class Solution {
public:

    int ways(vector<int> &dp,int pos,int n)
    {
        if(pos==n) return 1;
        if(pos>n) return 0;

        if(dp[pos]!=-1) return dp[pos];

        int totways = ways(dp,pos+1,n)+ways(dp,pos+2,n);
        return dp[pos]=totways;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);

        int ans = ways(dp,0,n);
        return ans;
    }
};