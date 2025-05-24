class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int a = 0;
        int b = 0;
        int k1 = k;
        int ans = 0;
        while(b<n)
        {
            
            if(nums[b]==0)
            {
                if(k1>0)
                {
                k1--;
                b++;}
                else
                {
                    ans=max(b-a,ans);
                    if(nums[a]==0)
                    {
                        k1++;
                        a++;
                    }
                    else
                    {
                        a++;
                    }
                }
            }
            else
            {
                b++;
            }
        }

        ans=max(b-a,ans);
        return ans;
    }
};