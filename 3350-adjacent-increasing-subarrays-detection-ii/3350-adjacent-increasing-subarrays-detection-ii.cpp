class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        int cnt=1;
        int maxv = 0;

        for(int i=0; i<n-1; i++)
        {
            if(nums[i+1]>nums[i])
            {
                cnt++;

            }
            else
            {
                if(cnt!=1)
                {
                    maxv=max(maxv,cnt);
                    ans.push_back(cnt);
                }
                else ans.push_back(0);

                cnt=1;
            }
        }
        if(cnt!=1) {maxv=max(maxv,cnt);ans.push_back(cnt);}
        else ans.push_back(0);
        int anss = maxv/2;

        if(ans.size()==1) return anss;
        
        int g = ans.size();
        for(int i=0; i<g-1; i++)
        {
            anss=max(anss,min(ans[i],ans[i+1]));
        }
        if(anss==0) return 1;
        return anss;
        


    }
};