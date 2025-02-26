class Solution {
public:
    // int func(vector<vector<int>>& v, vector<vector<int>>& dp,int m,int n,int m1,int n1){
    //     if(m==m1-1 && n==n1-1){
    //         if(v[m][n]==0) return 1;
    //         else return -2e9;
    //     }
        
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     if(v[m][n]!=0) return dp[m][n]=-2e9;
    //     int a=0;
    //     int b=0;
    //     if(m<(m1-1)){
    //         a=func(v,dp,m+1,n,m1,n1);

    //     }
    //     if (n<n1-1) b= func(v,dp,m,n+1,m1,n1);
        

    //     if(a<0) a=0;
    //     if(b<0) b=0;
    //     return dp[m][n]=a+b;

    // }

    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> dp(m,vector<int> (n,-1));

       if(v[m-1][n-1]==1) return 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(v[i][j]==1) dp[i][j]=-2e9;
            }
        }

       dp[m-1][n-1]=1;
       for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(dp[i][j]==-1){
            int a=0;
            int b=0;
            if(i!=m-1) {
                a=dp[i+1][j];

            }
            if(j!=n-1) b=dp[i][j+1];

            if(a<0) a=0;
            if(b<0) b=0;
            dp[i][j]=(long long)a+b;

            }
        }
       }

        return max(0,dp[0][0]);


    }
};