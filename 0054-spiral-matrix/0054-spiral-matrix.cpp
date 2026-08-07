class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // first row - --->
        // last column : bottom direction
        // last row -- <---- direction
        //first column : up direction
        int p = 0;
        int p1 = n-1;
        int c=0;
        int c1=m-1;
        vector<int> ans;
        int count = 0;
        while(1)
        {
            if(count==m*n) {break;}

            for(int i=c; i<=c1; i++)
            {
                ans.push_back(matrix[p][i]);
                count++;
            }
            p++;
            if(count==m*n) {break;}
            for(int i=p; i<=p1; i++)
            {
                ans.push_back(matrix[i][c1]);
                count++;
            }
            if(count==m*n) {break;}
            c1--;
            for(int i=c1; i>=c; i--)
            {
                ans.push_back(matrix[p1][i]);
                count++;
            }
            if(count==m*n) {break;}
            p1--;
            for(int i=p1; i>=p; i--)
            {
                ans.push_back(matrix[i][c]);
                count++;
            }
            c++;
        }
        return ans;
    }
};