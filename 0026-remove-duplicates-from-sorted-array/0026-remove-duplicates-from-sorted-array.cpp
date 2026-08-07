class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int lastelement=-101;
        int in = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]>lastelement)
            {
                lastelement=nums[i];
                nums[in]=lastelement;
                in++;
            }
        }
        return in;   
    }
};