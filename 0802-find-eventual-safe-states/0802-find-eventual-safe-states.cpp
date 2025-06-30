class Solution {
public:

   void dfs(int n, vector<vector<int>>& graph, vector<int> &visited) {
    if (graph[n].empty()) {
        visited[n] = 1;  
        return;
    }

    visited[n] = 2; 

    for (int it : graph[n]) {
        if (visited[it] == 0) {
            dfs(it, graph, visited);
        }

        if (visited[it] == 2) {
            
            return;
        }
    }

    visited[n] = 1; }



    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);

        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            if(visited[i]==0)
            {
                dfs(i,graph,visited);

            }
            if(visited[i]==1) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;


    }
};