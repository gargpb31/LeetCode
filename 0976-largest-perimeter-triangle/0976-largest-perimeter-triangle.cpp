class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(nums.rbegin(),nums.rend());

        for(int i=1; i<n-1; i++)
        {
            int sum = nums[i]+nums[i+1];
            if(sum>nums[i-1])
            {
                return sum+nums[i-1];
            }
        }
        return 0;

    }
};