class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> v(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});

        vector<vector<int>> effort(n,vector<int> (m,1e9));
        effort[0][0]=0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int dis = it.first;
            int xc=it.second.first;
            int yc=it.second.second;

            int row[]={-1,1,0,0};
            int col[]={0,0,1,-1};

            for(int i=0; i<4; i++)
            {
                int nr=row[i]+xc;
                int nc=col[i]+yc;

                if(nr>=0 && nc>=0 && nr<n && nc<m)
                {
                    int dif = abs(heights[nr][nc]-heights[xc][yc]);
                    int d = max(dif,effort[xc][yc]);
                    if(effort[nr][nc]>d)
                    {
                        effort[nr][nc]=d;
                        pq.push({d,{nr,nc}});
                    }
                } 
            }

        }

        return effort[n-1][m-1];
    }
};