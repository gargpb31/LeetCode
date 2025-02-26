class Solution {
public:
    int func (int n,vector<int> &dp){
        if(n==1) return 1;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=func(n-1,dp)+func(n-2,dp);
    }
 
    int climbStairs(int n) {
        
       int a = 1;
       int b=1;
        for(int i=2; i<=n; i++){
            int c = a+b;
            a=b;
            b=c;
        }
        return b;;
    }
};