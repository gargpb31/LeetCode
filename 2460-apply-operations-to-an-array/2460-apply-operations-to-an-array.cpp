class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans(nums.size(),0);

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int ans_index=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                ans[ans_index]=nums[i];
                ans_index++;
            }
        }
        return ans;
    }
};