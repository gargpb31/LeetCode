class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,0);
        dp[n-1]=0;

        for(int i=n-2; i>=0; i--)
        {
           
                
                int y = i + nums[i];
                if(y>=n-1)
                {
                    dp[i]=1;
                }
                else
                {
                    int r = 1e5;
                    for(int j = 1; j<=nums[i]; j++)
                    {
                        r=min(r,dp[i+j]);
                    }
                    dp[i]=r+1;
                }
            
         }
         
         return dp[0];
    }
};