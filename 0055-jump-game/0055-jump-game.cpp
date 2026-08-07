class Solution {
public:
    bool canJump(vector<int>& nums) {
        int st = 1;
        int n = nums.size();
        int tr = n;
        int r = st+nums[0];
        int i = 2;
        while(i<=r)
        {
            if(i==n+1) break; 
            int u = i+nums[i-1];
            r=max(r,u);
            i++;
        }
        if(r>=n) return true;
        return false;
    }
};