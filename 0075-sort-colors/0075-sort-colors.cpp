class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int c=0;
        int c1=0;
        int c2=0;

        for(int i=0; i<n; i++)
        {
            if(nums[i]==0) c++;
            else if(nums[i]==1) c1++;
            else c2++;
        }

        for(int i=0; i<n; i++)
        {
            if(c>0)
            {
                nums[i]=0;
                c--;
            }
            else if(c1>0)
            {
                nums[i]=1;
                c1--;
            }
            else nums[i]=2;
        }
        
    }
};