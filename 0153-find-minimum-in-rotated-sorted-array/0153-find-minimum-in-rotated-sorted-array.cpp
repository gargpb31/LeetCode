class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = 5001;
        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(nums[mid]<=nums[high])
            {
                if(nums[low]<=nums[mid])
                {
                    return nums[low];
                }
                else 
                {
                    if(nums[mid-1]>nums[mid]) return nums[mid];
                    else 
                    high=mid-1;
                }
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }
};