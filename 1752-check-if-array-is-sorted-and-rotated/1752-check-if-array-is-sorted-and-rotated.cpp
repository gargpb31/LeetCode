class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for(int i=0; i<n; i++)
        {
            int x = (i+1)%n;
            if(nums[i]>nums[x])
            {
                c++;
            }
        }
        if(c>1) return false;
        return true;
    }
};