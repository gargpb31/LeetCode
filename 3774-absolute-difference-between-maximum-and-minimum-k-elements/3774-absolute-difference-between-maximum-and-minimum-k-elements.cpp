class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int sum =0,sum2=0;
        sort(nums.begin(),nums.end());

        for(int i=0; i<k; i++) sum+=nums[i];
        sort(nums.rbegin(),nums.rend());
        for(int i=0; i<k; i++) sum2+=nums[i];
        return sum2-sum;

    }
};