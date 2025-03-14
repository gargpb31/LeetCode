class Solution {
public:
    void dfs(vector<vector<int> > &v, int n, vector<int> &vi){
        vi[n]=1;
        for(int i=0; i<v[n].size(); i++){
            if(vi[v[n][i]]==0){
                dfs(v,v[n][i],vi);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int> > v1(n+1);
        vector<int> vi(n+1,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(v[i][j]==1){
                    v1[i+1].push_back(j+1);
                    v1[j+1].push_back(i+1);
                }
            }
        }
        int c =0;
        for(int i=1; i<=n; i++){
            if(vi[i]==0){
                c++;
                dfs(v1,i,vi);
            }
        }
        return c;

        
    }
};