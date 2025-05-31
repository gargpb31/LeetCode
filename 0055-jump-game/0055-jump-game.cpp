class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0;
        int l = 0;
        int n = nums.size();
        while(l<n-1 && start<=l)
        {
            int y = nums[start];
            l=max(l,start+y);
            start++;
        }
        if(l>=(n-1)) return true;
        return false;

    }
};