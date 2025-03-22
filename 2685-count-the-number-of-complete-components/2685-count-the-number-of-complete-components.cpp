class Solution {
public:

    int minimum_degree;
    int totalvertexincmponenets;
    
    void dfs(int n,vector<vector<int>> &graph,vector<int> &visited){
        visited[n]=1;

        for(auto it : graph[n]){
            if(visited[it]==0){
                dfs(it,graph,visited);
            }
        }
        int y = graph[n].size();
        minimum_degree=min(minimum_degree,y);
        totalvertexincmponenets++;
    }



    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<int> visited(n,0);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                minimum_degree=100;
                totalvertexincmponenets=0;
                dfs(i,graph,visited);
                if(totalvertexincmponenets-1==minimum_degree) ans++;
            }
        }
        return ans;



    }
};