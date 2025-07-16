class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = nums[0];
       
        int n = nums.size();
        for(int i=1; i<n; i++)
        {
            if(i>start) return false;
            int y = i+nums[i];
            start=max(start,y);
            if(start>=n-1) return true;
        }
        return true;

    }
};