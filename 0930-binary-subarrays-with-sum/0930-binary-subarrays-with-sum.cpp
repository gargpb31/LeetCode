class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        map<int,int> m;
        m[0]=1;
        int sum =0;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            ans+=(m[sum-goal]);
            m[sum]++;
        }
        return ans;
    }
};