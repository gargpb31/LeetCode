class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       

        vector<vector<pair<int,int>>> v(n);

        for(auto it : flights)
        {
            v[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<long,pair<int,int>>, vector<pair<long,pair<int,int>>> , greater<pair<long,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        vector<vector<long>> dis(n,vector<long>(k+2,1e9));

        dis[src][0]=0;

        while(!pq.empty())
        {
            auto it = pq.top(); pq.pop();
            long dist=it.first;
            int poi = it.second.first;
            int cur = it.second.second;

            if(cur==k+1) continue;
            if(dis[poi][cur]<dist) continue;

            for(auto it : v[poi])
            {
                long newd = dist+it.second;
                if(newd<dis[it.first][cur+1])
                {
                    dis[it.first][cur+1]=newd;
                    pq.push({newd,{it.first,cur+1}});
                }
            }
        }

       long ans = 1e9;
        for(int i=0; i<=k+1;i++)
        {
            ans=min(ans,dis[dst][i]);
        }

        if(ans==1e9) return -1;
        return (int)ans;
    }
};