class Solution {
public:
map<int,int> m;

bool ans(int jump, vector<vector<int>> &dp,int n,int end)
    {
        if(n==end) return true;
        if(m.find(n)==m.end()) return false;

        if(dp[m[n]][jump]!=-1) return dp[m[n]][jump];

        bool k1 = ans(jump+1,dp,n+jump+1,end);
        bool k2 = ans(jump,dp,n+jump,end);
        bool ans1 = k1|k2;
        if(jump!=1)
        {
            bool k3 = ans(jump-1,dp,n+jump-1,end);
            ans1=ans1|k3;
        }
        return dp[m[n]][jump]=ans1;

    }


    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i=0; i<n; i++) m[stones[i]]=i;
        
        
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return ans(1,dp,1,stones[n-1]);

    }
};