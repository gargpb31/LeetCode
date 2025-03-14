//CODE USING DFS



class Solution {
public:
    
    void dfs(vector<vector<int>> &image,int sr,int sc, int color,int icolor){
        
        int row[] = {-1,0,+1,0};
        int col[] = {0,+1,0,-1};
        image[sr][sc]=color;
        for(int i=0; i<4; i++){
            int nrow = sr+row[i];
            int ncol = sc+col[i];

            if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size()){
                if(image[nrow][ncol]==icolor) dfs(image,nrow,ncol,color,icolor);
            }
        }
       
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int icolor = image[sr][sc];
        if(icolor!=color)
        dfs(image,sr,sc,color,icolor);
        return image;
    }
};