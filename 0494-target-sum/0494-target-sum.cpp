class Solution {
public:
    int ans(vector<int> &nums,int target,int n,vector<vector<int>> &dp)
    {
        if(n<0)
        {

            if(target==0) return 1;
            return 0;
        }
        if(dp[n][target+20000]!=-1) return dp[n][target+20000];
        int minus = ans(nums,target+nums[n],n-1,dp);
        int plus = ans(nums,target-nums[n],n-1,dp);

        int ways = minus+plus;

        return dp[n][target+20000]=ways;
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(40005,-1));

        return ans(nums,target,n-1,dp);
    }
};