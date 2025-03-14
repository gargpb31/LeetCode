class Solution {
public:
    //BY USING BFS APPROACH

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>> visited(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),-1));
        int row[] = {-1,0,+1,0};
        int col[] = {0,-1,0,+1};

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;

            q.pop();
            visited[x][y]=1;
            ans[x][y]=dis;
            for(int i=0; i<4; i++){
                int nrow = x+row[i];
                int ncol = y+col[i];

                if(nrow>=0 && nrow<mat.size() && ncol>=0 && ncol<mat[0].size()){
                    if(visited[nrow][ncol]==0) {
                        visited[nrow][ncol]=1;
                        q.push({{nrow,ncol},dis+1});

                    }
                }
            }



        }
        return ans;


    }
};