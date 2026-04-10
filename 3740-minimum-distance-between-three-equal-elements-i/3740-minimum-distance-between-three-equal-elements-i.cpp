class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(n+1);
        for(int i=0; i<n; i++)
        {
            v[nums[i]].push_back(i);
        }
        int ans = 2*n+1;
        for(int i=0; i<=n; i++)
        {
            int x = v[i].size();
            if(x>=3)
            {
                for(int j=0; j<x-2; j++)
                {
                    int dis = 2*(v[i][j+2]-v[i][j]);
                    ans=min(ans,dis);
                }
            }
        }
        if(ans==(2*n+1)) return -1;
        return ans;
    }
};