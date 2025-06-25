class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int g=0;
        int g1=1;
        vector<int> v(n);
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0)
            {
                v[g]=nums[i];
                g=g+2;
            }
            else
            {
                v[g1]=nums[i];
                g1+=2;
            }
        }
        return v;
    }
};