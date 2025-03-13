class Solution {
public:

    bool func(vector<int>& nums, vector<vector<int>>& queries,int mid){
        vector<int> v(nums.size()+1,0);
        for(int i=0; i<mid; i++){
            v[queries[i][0]]+=queries[i][2];
            v[queries[i][1]+1]-=queries[i][2];
        }
        for(int i=1; i<v.size(); i++){
            v[i]+=v[i-1];
        }
        for(int i=0; i<nums.size(); i++){
            if(v[i]<nums[i]){
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low=0;
        int high=queries.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(func(nums,queries,mid)){
                high=mid-1;
            }
            else low=mid+1;
        }
        if(low==queries.size()+1) return -1;
        return low;
    }
};