class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int ans=0;
        for(auto it : nums){
            if(it>=0) {sum+=it; ans=max(ans,sum);}
            else{
                ans=max(ans,sum);
                sum+=it;
                sum=max(sum,0);
            }
        }
        int ans2=0;
        sum=0;
        for(auto it : nums){
            if(it<=0) {
                sum+=it;
                ans2=min(ans2,sum);
            }
            else{
                ans2=min(ans2,sum);
                sum+=it;
                sum=min(0,sum);
            }
        }
        cout<<ans<<endl;
        return max(ans,abs(ans2));
        
    }
};