class Solution {
public:
    bool ans(map<int,int>&m, int cur, vector<vector<int>> &dp, int k,int end)
    {
        if(cur==end) return true;
        if(k >= dp.size()) return false;
        if(dp[m[cur]][k]!=-1)
        {
            return dp[m[cur]][k];
        }
        bool fina = false;
        int cur1 = cur+k;
        if(k>0)
        {
        if(m.find(cur1)!=m.end())
        {
            bool k1 = ans(m,cur1,dp,k,end);
            fina=fina|k1;
        }
        }
        int cur2 = cur+k+1;
        
        if(m.find(cur2)!=m.end())
        {
            bool k2 = ans(m,cur2,dp,k+1,end);
            fina=fina|k2;
        }
        if(k>1){
        int cur3 = cur+k-1;
            if(m.find(cur3)!=m.end())
            {
                bool k3 = ans(m,cur3,dp,k-1,end);
                fina=fina|k3;
            }

        }
       return dp[m[cur]][k]=fina;

    }


    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int,int> m;
        for(int i=0; i<n; i++) m[stones[i]]=i;

        vector<vector<int>> dp(n,vector<int>(n,-1));

        bool ans1 = ans(m,0,dp,0,stones[n-1]);
        return ans1;
        

    }
};