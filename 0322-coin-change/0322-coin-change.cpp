class Solution {
public:

    int ans(vector<int> &coins,int rem,vector<int> &dp)
    {
        if(rem==0) return 0;
        if(rem<0) return -1;

        if(dp[rem]!=-2) return dp[rem];

        int mini = INT_MAX;

        for(auto it : coins)
        {
            int res = ans(coins,rem-it,dp);
            if(res>=0 && res<mini)
            {
                mini=1+res;
            }
        }

        if(mini==INT_MAX)
        {
            return dp[rem]=-1;
        }
        return dp[rem]=mini;
    }


    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-2);
        return ans(coins,amount,dp);
    }
};