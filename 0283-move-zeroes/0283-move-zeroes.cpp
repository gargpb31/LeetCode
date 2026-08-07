class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        int z = 0;
        int in = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0); 
            else
            {
                nums[in]=nums[i];
                if(in!=i)
                nums[i]=0;
                in++;
            }
        }

    }
};