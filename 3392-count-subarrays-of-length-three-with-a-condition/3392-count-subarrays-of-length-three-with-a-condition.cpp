class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();

        int a = 0;
        int b = 2;

        if(n<3) return 0;

        int count = 0;

        while(b<n)
        {
            int sum = nums[a]+nums[b];

            int sum2 = nums[a+1]/2;
            if(nums[a+1]%2!=0) 
            {
                a++;
                b++;
                continue;
            }
            if(sum==sum2) count++;
            a++;
            b++;
        }
        return count;
    }
};