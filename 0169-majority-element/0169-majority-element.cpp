class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int ans = nums[0];
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==ans) count++;
        }
        if(count>(n/2)) return ans;
        ans=nums[n-1];
        count =0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==ans) count++;
        }
        if(count>(n/2)) return ans;
           ans=nums[n/2];
        count =0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==ans) count++;
        }
        if(count>(n/2)) return ans;
        return 0;

    }
};