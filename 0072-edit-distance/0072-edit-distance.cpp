class Solution {
public:

        int ans(int i,int j,string word1,string word2,vector<vector<int>> &dp){
            if(i<0 && j>=0) return j+1;
            if(i>=0 && j<0) return i+1;
            if(i==0 && j==0){
                if(word1[i]==word2[j]) return 0;
                return 1;
            }
            if(dp[i][j]!=-1) return dp[i][j];
            if(word1[i]==word2[j]) {
                int x1 = ans(i-1,j-1,word1,word2,dp);
                int x2 = 1+ans(i-1,j,word1,word2,dp);
                int x3 = 1+ans(i,j-1,word1,word2,dp);
                int an = min(x1,min(x2,x3));
                return dp[i][j]=an;


            } 
               int x1 = 1+ans(i-1,j-1,word1,word2,dp);
                int x2 = 1+ans(i-1,j,word1,word2,dp);
                int x3 = 1+ans(i,j-1,word1,word2,dp);
                int an = min(x1,min(x2,x3));
                return dp[i][j]=an;



        }


    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m =word2.size();
        if(n==0 && m==0) return 0;
        if(n==0 && m>0) return m;
        if(n>0 && m==0) return n;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return ans(n-1,m-1,word1,word2,dp);
    }
};