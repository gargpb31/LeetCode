class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int number = 0;
        queue<pair<int,int>> q;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1) {
                    
                    if(i==0 || j==0 || i==n-1 || j==m-1)
                    {
                        q.push({i,j});
                        grid[i][j]=3;
                        count++;
                    }
                    
                    number++;}
            }
        }

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

             q.pop();

             int row[]= {-1,0,+1,0};
             int col[] ={0,+1,0,-1};

             for(int i=0; i<4; i++)
             {
                int nr = x+row[i];
                int nc = y+col[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    if(grid[nr][nc]==1)
                    {
                        q.push({nr,nc});
                        grid[nr][nc]=3;
                        count++;
                    }
                }
             }
        }
        return number-count;




    }
};