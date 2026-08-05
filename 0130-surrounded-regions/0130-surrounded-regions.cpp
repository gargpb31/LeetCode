class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));

        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O')
                {
                    if(i==0 || j==0 || i==n-1 || j==m-1){q.push({i,j}); v[i][j]=-1;}
                    else v[i][j]=1;
                } 
            }
        }

        while(!q.empty())
        {
            auto [x,y] =q.front();
            q.pop();

            int dx[]={1,0,-1,0};
            int dy[]={0,1,0,-1};

            for(int i=0; i<4; i++)
            {
                int nr = x+dx[i];
                int nc=y+dy[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && v[nr][nc]==1)
                {
                    v[nr][nc]=-1;
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(v[i][j]==1) board[i][j]='X';
            }
        }
        
        
    }
};