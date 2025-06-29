class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int x =0,y=0;

        for(int i=n-1; i>=0; i--)
        {
            int z = max(nums[i]+y,x);
            y=x;
            x=z;
        }
        return x;
    }
};