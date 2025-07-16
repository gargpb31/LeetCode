class Solution {
public:
    bool check(vector<int> &nums,int k,int mid)
    {
        int n = nums.size();
        int c = 0;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]>mid) return false;
            if(sum+nums[i]>mid)
            {
                c++;
                sum=nums[i];
            }
            else
            {
                sum+=nums[i];
            }
        }
        c++;
        if(c<=k) return true;
        return false;

    }


    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *min_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(low<=high)
        {
            int mid = (low+(high-low)/2);

            if(check(nums,k,mid))
            {
                ans = mid;
                high = mid-1;
            
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
        

    }
};