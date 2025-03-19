class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1);
            else{
                count++;
                if(i+1==n || i+2==n) return -1;
                for(int j=0; j<3; j++){
                    nums[i+j]=1-nums[i+j];
                }


            }
        }
        return count;
    }
};