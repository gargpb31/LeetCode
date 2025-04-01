class Solution {
public:
    long long ans(vector<vector<int>>& questions,int n,vector<long long> &dp)
    {
        int m = questions.size();

        if(n==m-1)
        {
            return questions[n][0];
        }
        if(dp[n]!=-1) return dp[n];

        int g = n+questions[n][1]+1;
        
        long long pick = questions[n][0];
        if(g<=m-1)
        {
            pick += ans(questions,g,dp);
        }
        long long npick = ans(questions,n+1,dp);

        return dp[n]=max(npick,pick);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n,-1);

        return ans(questions,0,dp);
    }
};