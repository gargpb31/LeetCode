class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        vector<int> v;
          int n = nums.size();

        for(int i = 0; i<n; i++)
        {
            v.push_back(nums[i]);
        }

        sort(v.begin(),v.end());
      
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            int low = lower-nums[i];
            int hig = upper-nums[i];

            auto it = lower_bound(v.begin(),v.end(),low);
            int ind = it-v.begin();

            auto it2 = upper_bound(v.begin(),v.end(),hig);
            int ind2 = it2-v.begin();

            int size = ind2-ind;

            if(nums[i]>=low && nums[i]<=hig) size--;

            ans+=(size);
            

        }
        return ans/2;

    }
};