class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int low = 0;
        int high = n;
        if(n==0) return nums[0];

        while(low+1<high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==nums[mid+1])
            {
                int n1 = high-mid-1;
                int n2 = mid-low;
                if(n1%2!=0) 
                {
                    if(n1==1) return nums[high];
                    low=mid+2;
                }
                else 
                {
                    if(n2==1) return nums[low];
                    else high=mid-1;
                }
            }
            else if (nums[mid]==nums[mid-1])
            {
                int n1 = mid-low-1;
                int n2 = high-mid;
                if(n1%2!=0)
                {
                    if(n1==1) return nums[low];
                    high=mid-2;
                }
                else
                {
                    if(n2==1) return nums[high];
                    low=mid+1;
                }

            }
            else return nums[mid];
        }
        return -1;
    }
};