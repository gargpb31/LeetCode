class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n = numCourses;
        vector<vector<int>> graph(n);

        int l = p.size();
        vector<int> in(n,0);
        for(int i=0; i<l; i++)
        {
            graph[p[i][1]].push_back(p[i][0]);
            in[p[i][0]]++;
        }

        queue<int> q;

        for(int i=0; i<n; i++)
        {
            if(in[i]==0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty())
        {
            int x = q.front();

            q.pop();
            ans.push_back(x);

            for(auto it : graph[x])
            {
                in[it]--;
                if(in[it]==0)
                {
                    q.push(it);
                }
            }
        }

        if(ans.size()==n) return true;
        return false;

        
    }
};