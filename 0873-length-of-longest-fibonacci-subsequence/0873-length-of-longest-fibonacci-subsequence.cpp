class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        map<int,int> m;
        int g=0;
        for(auto it : arr) {
            m[it]=g;
            g++;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x = arr[i]+arr[j];
                if(m.find(x)!=m.end()) {
                    dp[i][j]=1;
                    int y = arr[j]-arr[i];
                    if(m.find(y)!=m.end()){
                        dp[i][j]+=dp[m[y]][i];
                    }
                }
            }
        }
        for(auto it :dp){
            for(int i=0; i<it.size(); i++){
                ans=max(ans,it[i]);
            }
            
        }
        if(ans==0) return 0;
        return ans+2;


    }
};