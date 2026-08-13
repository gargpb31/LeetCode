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

        vector<int> dp(n,-1);

        return ans(dp,n-1,nums,0);
        
    }
};