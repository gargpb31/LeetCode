class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int a1=*max_element(nums.begin(),nums.end());
        if(a1<0) ans=a1;
        int sum = 0;

        for(int i=0; i<n; i++)
        {

            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
        }

        return ans;
    }
};