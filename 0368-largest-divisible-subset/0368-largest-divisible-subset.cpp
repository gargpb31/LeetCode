class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n+1,0);
      map<int,int> m;
       
       dp[0]=1;
       m[0]=-1;
       
       for(int i=1; i<n; i++)
       {
            int ans = 0;
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    ans=max(ans,dp[j]);
                }
            }
            dp[i]=ans+1;
            if(ans!=0)
            {   
            for(int j=0; j<i; j++)
            {
                
                if(nums[i]%nums[j]==0)
                {
                    if(ans==dp[j])
                    {
                        m[i]=j;
                        break;
                    }
                }
            }
            }
            else
            {
                m[i]=-1;
            }
            
       }
       vector<int> ans1;
       int ans2 = *max_element(dp.begin(),dp.end());
       for(int i=0; i<n; i++)
       {
           if(ans2==dp[i])
           {
               ans1.push_back(nums[i]);
               int y = m[i];
               while(y!=-1)
               {
                   ans1.push_back(nums[y]);
                   int x = m[y];
                   y=x;
                   
                   
               }
               reverse(ans1.begin(),ans1.end());
               
               return ans1;
               
               
           }
       }
       return ans1;
       
    }
};