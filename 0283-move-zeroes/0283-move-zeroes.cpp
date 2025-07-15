class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return;

        int ze = -1;
        int nze =-1;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
            {
                if(ze==-1)
                ze=i;
            }
            else
            {
                nze=i;
            }

            if(ze<nze && ze!=-1) 
            {
                swap(nums[ze],nums[nze]);
                ze++;
                nze=-1;

            }

        }
    }
};