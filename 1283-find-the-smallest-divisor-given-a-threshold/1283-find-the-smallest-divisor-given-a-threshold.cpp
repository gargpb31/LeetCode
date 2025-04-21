class Solution {
public:
    bool check(vector<int>& nums, int threshold,int mid)
    {
        long long sum = 0;

        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            int csum = nums[i]/mid;
            if(nums[i]%mid!=0) csum++;

            sum+=(csum);
        }

        long long t = threshold;

        if(sum<=t) return true;
        return false;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = 1e6;

        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(check(nums,threshold,mid))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};