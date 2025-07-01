class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[n-1][n-1]==1) return -1;

        queue<pair<int,pair<int,int>>> q;
        q.push({1,{n-1,n-1}});
        vector<vector<int>> ans(n,vector<int>(n,1e8));
        ans[n-1][n-1]=1;

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second.first;
            int z = q.front().second.second;
            q.pop();
            if(y==0 && z==0) return x;
            int row [] = {-1,-1,-1,+1,+1,+1,0,0};
            int col[] = {+1,0,-1,+1,-1,0,-1,+1};
            if(ans[y][z]<(x)) continue;
            for(int i=0; i<8; i++)
            {
                int nr = y+row[i];
                int nc = z+col[i];
                if(nr>=0 && nc>=0 && nc<n && nr<n)
                {
                    if(grid[nr][nc]==0)
                    {
                        if(ans[nr][nc]>(x+1))
                        {
                            ans[nr][nc]=x+1;
                        q.push({x+1,{nr,nc}});

                        }
                    }
                }
            }
        }
        return -1;



    }
};