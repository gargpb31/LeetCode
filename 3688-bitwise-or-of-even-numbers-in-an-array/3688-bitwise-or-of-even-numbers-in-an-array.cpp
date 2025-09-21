class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(auto it : nums)
        {
            if(!(it&1))
            {
                ans=ans|it;
            }
        }
        return ans;
    }
};