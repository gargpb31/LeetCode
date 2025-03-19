class Solution {
public:
    bool func(vector<int> &nums,int mid){
        int count=0;
        int a=0;
        int b=2;
        int n = nums.size();
        vector<int> v = nums;
        while(b<n){
            if(v[a]==1) {
                a++;
                b++;
            }
            else{
                count++;
                for(int i=0; i<3; i++){
                    v[a+i]=1-v[a+i];
                }
                a++;
                b++;
            }
        }
        for(int i=0; i<n; i++){
            if(v[i]==0) return false;
        }
        
        if(count<=mid) return true;
        return false;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(func(nums,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        
        }
        if(low==n+1) return -1;
        return low;
    }
};