class Solution {
public:
    long long splitArray(vector<int>& nums) {
       

     
        int n = nums.size();
         vector<int> v1(n,0),v2(n,0);
         v1[0]=1;
        for(int i=1; i<n; i++)
        {
            if(nums[i]>nums[i-1])
            {
                v1[i]=1;
            }
            else
            {
                break;
            }
        }

        v2[n-1]=1;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]>nums[i+1]) v2[i]=1;
            else break;
        }

        long long sum=0;
        for(int i=0; i<n; i++) sum+=nums[i];
        long long sum2=0;
        long long ans = LLONG_MAX;

        for(int i=0; i<n-1; i++)
        {
            sum2+=nums[i];
            sum-=nums[i];
            if(v1[i]==1 && v2[i+1]==1)
            {
                ans=min(ans,abs(sum-sum2));
            }

        }
        if (ans == LLONG_MAX) return -1; 
        return ans;
        
    }
};