class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> v(n),v1(m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==0)
                {
                    v[i]=1;
                    v1[j]=1;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(v[i]==1 || v1[j]==1) matrix[i][j]=0;
            }
        }
       
    }

};