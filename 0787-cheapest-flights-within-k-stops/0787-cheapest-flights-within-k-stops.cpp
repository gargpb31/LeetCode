class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        int f = flights.size();

        for(int i=0; i<f; i++)
        {
        graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> pq;

   vector<vector<int>> dist(n, vector<int>(k+2, 1e8));
dist[src][0] = 0;
  
    pq.push({{0,0},src});
   
    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        

            if (p.first.second > k) continue;
        for(auto it : graph[p.second])
        {
            int nv = p.first.first+it.second;
            if (dist[it.first][p.first.second + 1] > nv) {
    dist[it.first][p.first.second + 1] = nv;
    pq.push({{nv, p.first.second + 1}, it.first});
}
        }
    }
    int minCost = *min_element(dist[dst].begin(), dist[dst].end());
        return minCost == 1e8 ? -1 : minCost;
               
    }
};