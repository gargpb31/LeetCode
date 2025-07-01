class Solution {
public:
    int countPaths(int n, vector<vector<int>>& road) {
        vector<vector<pair<int,int>>> graph(n);
        int r = road.size();
        for(int i=0; i<r; i++)
        {
             graph[road[i][0]].push_back({road[i][1], road[i][2]});
            graph[road[i][1]].push_back({road[i][0], road[i][2]}); 
        }
        int M = 1e9+7;

        vector<long long> ans(n,1e18);
       
        vector<int> ways(n,0);
        ways[0]=1;
        ans[0]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0}); 

        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            if(ans[p.second]<p.first) continue;
            
            for(auto it : graph[p.second])
            {
                long long nw = it.second+p.first;
                if(ans[it.first]>nw)
                {
                    ans[it.first]=nw;
                    ways[it.first]=(ways[p.second]);
                    pq.push({nw,it.first});
                }
                else if(ans[it.first]==nw)
                {
                    ways[it.first]+=(ways[p.second]);
                    ways[it.first]%=(M);
                }
            }
        }
        return ways[n-1];

    }
};