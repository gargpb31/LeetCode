class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int s1 = *max_element(nums.begin(),nums.end());
        int s2 = *min_element(nums.begin(),nums.end());
        
        long long ans = (long long)(s1-s2)*k;
        return ans;
    }
};