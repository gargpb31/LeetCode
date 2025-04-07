class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        for(int i=0; i<n; i++) sum+=nums[i];
        if(sum%2!=0) return false;

        sum/=2;

        vector<bool> v1 (sum+1,0);
        vector<bool> v2 (sum+1,0);
        v1[0]=true; v2[0]=true;
        if(nums[0]<=sum)
        v1[nums[0]]=true;

        for(int i=1; i<n; i++){
            for(int j=1; j<=sum; j++){
                bool ntake = v1[j];
                bool take =false;
                if(nums[i]<=j){
                    take=v1[j-nums[i]];
                }
                v2[j]=(take|ntake);
            }
            v1=v2;
        }
        return v1[sum];
    }
};