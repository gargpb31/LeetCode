class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> ans(n,vector<int>(n,1e8));

       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;

       q.push({grid[n-1][n-1],{n-1,n-1}});
       ans[n-1][n-1]=grid[n-1][n-1];

       while(!q.empty())
       {
        auto p = q.top();
        q.pop();

        if(ans[p.second.first][p.second.second]<p.first) continue;

        int row[] = {-1,1,0,0};
        int col[]={0,0,+1,-1};

        for(int i=0; i<4; i++)
        {
            int nr = p.second.first+row[i];
            int nc = p.second.second+col[i];

            if(nr>=0 && nc>=0 && nr<n && nc<n)
            {
                int nw = max(grid[nr][nc],p.first);
                if(ans[nr][nc]>nw)
                {
                    ans[nr][nc]=nw;
                    q.push({nw,{nr,nc}});
                }
            }
        }
       }
       return ans[0][0];

       
    }
};