class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        if(grid[0][0]==1) return -1;
        pq.push({1,{0,0}});

        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0]=1;

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();     

            int dist = it.first;
            int xc=it.second.first;
            int yc=it.second.second;

            if(dis[xc][yc]<dist) continue;

            int row[] = {-1,0,0,1,1,1,-1,-1};
            int col[] = {0,1,-1,0,1,-1,1,-1};

            for(int i=0; i<8; i++)
            {
                int nr=row[i]+xc;
                int nc=col[i]+yc;

                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==0)
                {
                    if((dist+1)<dis[nr][nc])
                    {
                        dis[nr][nc]=dist+1;
                        pq.push({dist+1,{nr,nc}});
                    }
                }
            }


        }

        if(dis[n-1][m-1]!=1e9) return dis[n-1][m-1];
        return -1;
        
    }
};