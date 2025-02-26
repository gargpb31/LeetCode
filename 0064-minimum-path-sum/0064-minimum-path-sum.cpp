class Solution {
public:
  //space optimized solution 


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> v1(n,-1);
        v1[n-1]=grid[m-1][n-1];
        for(int i=m-1; i>=0; i--){
            vector<int> v2(n,-1);
            for(int j=n-1; j>=0; j--){
                    if(i==m-1 && j==n-1) v2[j]=grid[i][j];
                    else{
                    int a=1e5;
                    int b=1e5;
                    if(i!=m-1) a=v1[j];
                    if(j!=n-1) b=v2[j+1];

                    v2[j]=grid[i][j]+min(a,b);}
                
            }
            v1=v2;
        }
        return v1[0];

    }
};