class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int f = -1e6;
        for(int i=0; i<n; i++)
        {
            if(nums[i]<0)
            {
                if(ans==0) 
                {
                    ans=1;
                }
                ans*=(nums[i]);
                f=max(f,ans);
            }
            else
            {
                if(ans==0)
                {
                    ans=1;
                }
                ans*=(nums[i]);
                f=max(f,ans);
            }
        }
        ans=0;
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i]<0)
            {
                if(ans==0) 
                {
                    ans=1;
                }
                ans*=(nums[i]);
                f=max(f,ans);
            }
            else
            {
                if(ans==0)
                {
                    ans=1;
                }
                ans*=(nums[i]);
                f=max(f,ans);
            }
        }
        return f;
    }
};