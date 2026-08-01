class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size()-1;
        int low = 0;
        int high = n;
        if(n==0) return 0;
        while(low+1<high)
        {
            int mid = (low+high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
            else if (nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1])
            {
                low=mid;
            }
            else
            {
                high=mid;
            }
            
        }
        if(nums[0]>nums[1]) return 0;
        else return n;
        
    }
};