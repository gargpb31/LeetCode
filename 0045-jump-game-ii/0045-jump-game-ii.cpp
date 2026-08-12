class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]==0 || n==1) return 0;
        int cur = 1+nums[0];
        int ans = 1;
        int ne = cur;
        int i = 2;
        while(i<=cur)
        {   
            if(i>=n) break;
            ne=max(ne,nums[i-1]+i);
            if(i==cur)
            {
                cur=ne;
                ans++;
            }
            i++;
        }
        return ans;
    }
};