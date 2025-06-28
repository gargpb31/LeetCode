class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                if(board[i][j]=='O') {q.push({i,j});
                board[i][j]='I';}
                }
            }
        }

        while(!q.empty())
        {
            int x1 = q.front().first;
            int y1 = q.front().second;

            q.pop();

            int row[] = {-1,0,+1,0};
            int col[]={0,-1,0,+1};

            for(int i=0; i<4; i++)
            {
                int nr =x1+row[i];
                int nc = y1+col[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    if(board[nr][nc]=='O')
                    {
                        q.push({nr,nc});
                        board[nr][nc]='I';
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='I') board[i][j]='O';
            }
        }
        

    }
};