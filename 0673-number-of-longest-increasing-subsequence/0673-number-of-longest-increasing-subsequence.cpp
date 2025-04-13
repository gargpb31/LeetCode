class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        vector<int> dp1(n);
        dp1[0]=1;
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
            if(ans==0){
                dp1[i]=1;
                continue;
            }
             for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[j]==ans)
                    {
                        dp1[i]++;
                    }
                }
            }
            fina=max(fina,ans+1);
        }
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(fina==dp[i]) count+=dp1[i];
        }

        return count;
    }
};