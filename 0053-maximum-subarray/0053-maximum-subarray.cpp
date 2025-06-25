class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = -1e9;
        for(int i=0; i<n; i++)
        {
            if(nums[i]>=0) {sum+=nums[i]; ans=max(ans,sum);}
            else
            {
               
                sum+=nums[i];
                ans=max(ans,sum);
                if(sum<0) sum=0;
            }
        }
        
        return ans;
    }
};