class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[0]=1;
        int fina = 1;
        for(int i=1; i<n; i++)
        {
            int ans = 0;
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j])
                {
                    ans=max(ans,dp[j]);
                }
            }
            dp[i]=ans+1;
            fina=max(fina,ans+1);
        }
        return fina;

    }
};