class Solution {
public:
    bool check(vector<int>& nums) {
        int flag = 0;

        int n = nums.size();

        for(int i=0; i<n-1; i++)
        {
            if(nums[i+1]<nums[i]) flag++;
        }
        if(nums[n-1]>nums[0]) flag++;
        if(flag==1) return true;
        return false;
    }
};