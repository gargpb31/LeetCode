class Solution {
public:
    bool ans(vector<int> &nums,vector<vector<int>> &dp, int cur,int target)
    {
        if(target==0) return true;
        if(cur==nums.size()-1)
        {
            return nums[cur]==target;
        }

        if(dp[cur][target]!=-1) return dp[cur][target];

        bool ntake = ans(nums,dp,cur+1,target);
        if(target>=nums[cur])
        {
            bool take = ans(nums,dp,cur+1,target-nums[cur]);
            ntake=ntake|take;
        }
        return dp[cur][target]=ntake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum%2==1) return false;
        int target =  sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return ans(nums,dp,0,target);
    }
};