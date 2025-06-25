class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int g=0,g1=0;
        vector<int> v;
        int flag = 0;
        while(g<n && g1<m)
        {  if(matrix[g][g1]==101) break;
            if(flag==0)
            {
               

                v.push_back(matrix[g][g1]);
                matrix[g][g1]=101;

                if(g1==m-1)
                {
                    flag=1;
                    g++;
                }
                else if (matrix[g][g1+1]==101)
                {
                    flag=1;
                    g++;
                }
                else g1++;
            }
            else if(flag==1)
            {
             v.push_back(matrix[g][g1]);
                matrix[g][g1]=101;
                if(g==n-1) 
                {
                    flag=2;
                    g1--;
                }
                else if(matrix[g+1][g1]==101) {g1--; flag=2;}
                else g++;
            }
            else if(flag==2)
            {
                 v.push_back(matrix[g][g1]);
                matrix[g][g1]=101;

                if(g1==0)
                {
                    flag=3;
                    g--;
                }
                else if(matrix[g][g1-1]==101) {flag=3;  g--;}
                else g1--;
            }
            else
            {
                 v.push_back(matrix[g][g1]);
                matrix[g][g1]=101;
                if(g==0)
                {
                    flag=0;
                    g1++;
                }
                else if(matrix[g-1][g1]==101) {flag=0;   g1++;}
                else g--;
            }
        }
        return v;
    }
};