class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        vector<vector<int>> v(n,vector<int>(n,1e9));

      for(int i = 0; i < n; i++)

            v[i][i] = 0;

        for(auto it : edges)
        {
            v[it[0]][it[1]]=it[2];
            v[it[1]][it[0]]=it[2];
        }

        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(v[i][k]==1e9 || v[j][k]==1e9) continue;

                    if(v[i][j]==1e9)
                    {
                        v[i][j]=v[i][k]+v[k][j];
                    }
                    else
                    {
                        v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
                    }
                }
            }
        }

        vector<int> c(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]<=dist)
                {
                    c[i]++;
                }
            }
        }

        int dd = *min_element(c.begin(),c.end());
        for(int i=n-1; i>=0; i--)
        {
            if(c[i]==dd) return i;
        }
        return -1;
    }
};