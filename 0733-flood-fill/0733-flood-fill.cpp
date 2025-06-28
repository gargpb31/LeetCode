class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int start = image[sr][sc];
        if(start==color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty())
        {
            int x1 = q.front().first;
            int y1 = q.front().second;
            q.pop();

            int row[] = {-1,0,1,0};
            int col[] = {0,1,0,-1};

            for(int i=0; i<4; i++)
            {
                int nr = x1+row[i];
                int nc = y1+col[i];

                if(nr>=0  && nr<n && nc>=0 && nc<m)
                {
                    if(image[nr][nc]==start)
                    {
                        q.push({nr,nc});
                        image[nr][nc]=color;                   
                        }
                }
            }
        }
        return image;
    
    }
};