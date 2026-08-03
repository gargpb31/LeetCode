class Solution {
public:

    bool func(vector<int> &v, int k, int mid)
    {
        int n =v.size();
        int sum = 0;
        int c=0;
        for(int i=0; i<n; i++)
        {
            if(sum+v[i]<=mid) sum+=v[i];
            else
            {
                c++;
                sum=v[i];
            }
        }
        c++;


        if(c<=k) return true;
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(func(nums,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};