class Solution {
public:
    int countPairs(vector<int>& nums, int k) 
    {
        vector<vector<int>> v(101);

        for(int i=0; i<nums.size(); i++)
        {
            v[nums[i]].push_back(i);
        }

        int ans = 0;

        for(int i=0; i<=100; i++)
        {
            if(v[i].size()>=2)
            {
                int x = v[i].size();
                for(int j=0; j<x; j++)
                {
                    for(int k1=j+1; k1<x; k1++)
                    {
                        int mul = v[i][j]*v[i][k1];
                        if(mul%k==0) ans++;
                    }
                }
            }
        }

        return ans;
    }
};