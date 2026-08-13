class Solution {
public:
    int ans(vector<int> &dp, int n, vector<int> &nums, int cur)
    {
        if(cur==n){
            return nums[cur];
        }
        if(cur>n) return 0;

        if(dp[cur]!=-1) return dp[cur];

        int take = nums[cur]+ans(dp,n,nums,cur+2);
        int ntake = ans(dp,n,nums,cur+1);

       return dp[cur]=max(ntake,take);
    }


    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2; i<=n; i++)
        {
            dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
        }

        return dp[n];

    }
};