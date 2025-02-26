class Solution {
public:
    bool canJump(vector<int>& nums) {
        int g=0;
        for(auto it : nums){
            if((g+it)>=nums.size()-1) return true;
            g++;
        }
        return false;
    }
};