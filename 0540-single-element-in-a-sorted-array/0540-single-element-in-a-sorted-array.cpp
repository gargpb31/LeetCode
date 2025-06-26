class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        if(n==1) return nums[0];
        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(mid==0)
            {
                if(nums[mid+1]!=nums[mid]) return nums[mid];
            }
            else if(mid==n-1)
            {
                if(nums[mid-1]!=nums[mid]) return nums[n-1];

            }
            else
            {
if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid]) return nums[mid];
            }

            if(nums[mid-1]==nums[mid])
            {
                int nl = mid-low;
                int nr = high-mid;
                if(nr%2==0)
                {
                    high=mid;
                }
                else 
                {
                    low=mid+1;
                }
            }
            else
            {
                int nl = mid-low;
                if(nl%2==0)
                {
                    low=mid;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};