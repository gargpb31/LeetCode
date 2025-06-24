class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n,0);
        for(int i=0; i<n; i++)
        {
            if(nums[i]%2!=0) v[i]=1;
        }
        int sum=0;
        map<int,int> m;
        m[0]=1;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            sum+=v[i];
            ans+=(m[sum-k]);
            m[sum]++;
        }
        return ans;
    }
};