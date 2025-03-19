class Solution {
public:
    int ans(string s,int n,string s2,vector<vector<int>> &dp){
        if(n==s.size()-1){

            if(s2.size()==0){
            s2+=s[n];
            int x = stoi(s2);
           

            if(x>=1 && x<=26) return 1;
            
            return 0;}
            else{
                s2+=s[n];
            int x = stoi(s2);
           
            int ans2=0;
            if(x>=1 && x<=26) ans2++;
            s2.clear();
            s2+=s[n];
            x=stoi(s2);
            if(x>=1 && x<=26) ans2++;
            return ans2;
            
          
            }
        }

        int r = s2.size();
        if(dp[n][r]!=-1) return dp[n][r];

        if(s2.size()==0){
            s2+=s[n];
            int x = stoi(s2);
            if(x>=1 && x<=26){
                return dp[n][0]=ans(s,n+1,s2,dp);

            }
            else{
              return dp[n][0]=0;
            }

        }
    
            s2+=s[n];
            int x = stoi(s2);
            int ans2=0;
            int flag=0;
            if(x>=1 && x<=26){
                s2.clear();
                    ans2+=ans(s,n+1,s2,dp);
                    flag++;
            }
            s2.clear();
            s2+=s[n];
            x=stoi(s2);
             if(x>=1 && x<=26){
                    ans2+=ans(s,n+1,s2,dp);
                    flag++;
            }
            if(flag==0) return dp[n][1]=0;
            return dp[n][1]=ans2;
        
      
 

    }


    int numDecodings(string s) {
        string s2 = "";
            int n = s.size();

            vector<vector<int>> dp(n,vector<int>(2,-1));
            int y = ans(s,0,s2,dp);

           
            return y;
    }
};