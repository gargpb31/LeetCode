class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        map<int,int> m;
        m[0]=1;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            ans+=(m[sum-k]);
            m[sum]++;
        }
        return ans;
    }
};