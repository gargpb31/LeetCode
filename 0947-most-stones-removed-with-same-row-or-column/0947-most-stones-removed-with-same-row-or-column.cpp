
class DSU{

    public:
    vector<int> size,parent;

    public: 
    DSU(int n)
    {
        parent.resize(n,0);
        size.resize(n,1);
        for(int i=0; i<n; i++) parent[i]=i;
    }


    int findpar(int node)
    {
        if(parent[node]==node) return node;

        return parent[node]=findpar(parent[node]);
    }

    void unionby(int node1 ,int node2)
    {
        int p1 = findpar(node1);
        int p2 = findpar(node2);

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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int x = 2e4+2;
        DSU d(x);

        for(int i=0; i<n; i++)
        {
            d.unionby(stones[i][0],stones[i][1]+1e4+1);
        }

        vector<int> v(x,0);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int p = d.findpar(stones[i][0]);
            if(v[p]==0)
            {
                v[p]=1;
            }
            else
            {
                ans++;
            }

        }
        return ans;

    }
};