class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> v(n),v1(n);
        int maximum = 0;
      
        for(int i=0; i<n; i++)
        {
            maximum=max(maximum,nums[i]);
            
            v[i]=maximum;
           
        }
      

        maximum=0;
        for(int i= n-1; i>=0; i--)
        {
            maximum=max(maximum,nums[i]);
            v1[i]=maximum;
        }
       
        int ans=0;

        for(int i=1; i<n-1; i++)
        {
            int g = v1[i+1];
            int h = v[i-1];
            int ans2 = (h-nums[i])*g;
            ans=max(ans,ans2);
        }
        return ans;



    }
};