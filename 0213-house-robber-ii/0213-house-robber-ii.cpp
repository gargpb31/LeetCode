class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int x=0,y=0;
        for(int i=n-2; i>=0; i--)
        {
            int z = max(nums[i]+y,x);
            y=x;
            x=z;
        }
        int x1 = 0;
        y=0;
        for(int i=n-1; i>=1; i--)
        {
            int z = max(nums[i]+y,x1);
            y=x1;
            x1=z;
        }
        return max(x1,x);
    }
};