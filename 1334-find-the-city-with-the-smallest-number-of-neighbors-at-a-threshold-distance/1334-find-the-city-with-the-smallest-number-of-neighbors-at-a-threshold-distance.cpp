class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        int e = edges.size();

        for(int i=0; i<e; i++)
        {
            matrix[edges[i][0]][edges[i][1]]=edges[i][2];
            matrix[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0; i<n; i++)
        {
            matrix[i][i]=0;
        }

        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        int ans = 0;
        int c = n;
        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<n; j++)
            {
               if(matrix[i][j]<=distanceThreshold && i!=j) count++;
            }
            cout<<i<<" "<<count<<endl;
            if(count<c)
            {
                c=count;
                ans=i;
            }
            else if(c==count)
            {
                ans=max(ans,i);
            }

        }
        return ans;
    }
};