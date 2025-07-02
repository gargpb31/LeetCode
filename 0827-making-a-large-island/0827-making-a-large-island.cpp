class DSU{
    public : vector<int> parent,size;

    public : 

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);

        for(int i=0; i<n; i++) parent[i]=i;
    }


    int fipar(int node)
    {
        if(parent[node]==node) return node;

        return parent[node]=fipar(parent[node]);
    }

    void u(int node1,int node2)
    {
        int p1 = fipar(node1);
        int p2 = fipar(node2);

        if(p1==p2) return;

        if(size[p1]<size[p2])
        {
            parent[p1]=p2;
            size[p2]+=(size[p1]);
        }
        else
        {
            parent[p2]=p1;
            size[p1]+=(size[p2]);
        }
    }





};






class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DSU d(n*n);

        vector<vector<int>> visited(n,vector<int>(n,0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j]=1;

                    while(!q.empty())
                    {
                        auto p = q.front();
                        q.pop();
                        d.u(i*n+j,p.first*n+p.second);
                        int row[] = {-1,+1,0,0};
                        int col[] = {0,0,+1,-1};

                        for(int i1=0; i1<4; i1++)
                        {
                                int nr = p.first+row[i1];
                                int nc = p.second+col[i1];

                                if(nr>=0 && nc>=0 && nr<n && nc<n)
                                {
                                if(grid[nr][nc]==1 && visited[nr][nc]==0)
                                {
                                    q.push({nr,nc});
                                    visited[nr][nc]=1;
                                }
                                }
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n*n; i++)
        {
            ans=max(ans,d.size[i]);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0)
                {
                    int row[] = {-1,+1,0,0};
                    int col[] = {0,0,1,-1};
                    map<int,int> m5;
                    int anss = 0;
                    for(int i1=0; i1<4; i1++)
                    {
                        int nr = i+row[i1];
                        int nc = j+col[i1];
                        
                        if(nr>=0 &&nc>=0 && nr<n && nc<n)
                        {
                            if(grid[nr][nc]==1)
                            {
                                int h = d.fipar(nr*n+nc);
                                if(m5.find(h)==m5.end())
                                {
                                    m5[h]=1;
                                    anss+=d.size[h];
                                }
                            }
                        }
                    }
                    anss+=1;
                    ans=max(ans,anss);
                }
            }
        }
        return ans;
        
    }
};