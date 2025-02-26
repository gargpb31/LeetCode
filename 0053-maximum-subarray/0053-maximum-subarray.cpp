class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=-1e4;
        int flag=0;
        for(auto it : nums){
            if(it<0) {ans=max(ans,it);}
            else{
                flag++;
            }
        }
        if(flag==0) return ans;
        ans=0;
        for(auto it : nums){
            if(it>=0) {sum+=it; ans=max(ans,sum);}
            else{
                    ans=max(ans,sum);
                    sum+=it;
                    sum=max(0,sum);
            }
        }
        
        return ans;
    }
};