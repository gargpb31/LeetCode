class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int time = 0;

        queue<pair<int,pair<int,int>>> q;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                }
            }
        }

        int ans = 0;
        while(!q.empty())
        {
            int curtime = q.front().first;
            int x1 = q.front().second.first;
            int y1 = q.front().second.second;
            q.pop();
            int col[] = {-1,0,+1,0};
            int row[] = {0,1,0,-1};

            for(int i=0; i<4; i++)
            {
                int nr = x1+row[i];
                int nc = y1+col[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    if(grid[nr][nc]==1)
                    {
                        q.push({curtime+1,{nr,nc}});
                        grid[nr][nc]=2;
                        ans=max(ans,curtime+1);
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;

    }
};