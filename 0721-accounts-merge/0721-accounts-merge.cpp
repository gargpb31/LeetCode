class DSU{
    public : vector<int> parent,rank;

    public: DSU(int n)
    {
        rank.resize(n,0);
        parent.resize(n);

        for(int i=0; i<n; i++) parent[i]=i;
    }

    int finpar(int node)
    {
        if(parent[node]==node) return node;

        return parent[node]=finpar(parent[node]);
    }

    void uni(int node1,int node2)
    {
        int p1 = finpar(node1);
        int p2 = finpar(node2);

        if(p1==p2) return;

        if(rank[p1]<rank[p2])
        {
            parent[p1]=p2;

        }
        else if(rank[p2]<rank[p1])
        {
            parent[p2]=p1;
        }
        else 
        {
            parent[p2]=p1;
            rank[p1]++;
        }
    }

};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int> m;

        int n = accounts.size();
        DSU d(n);

        for(int i=0; i<n; i++)
        {
            int s = accounts[i].size();

            for(int j=1; j<s; j++)
            {
                if(m.find(accounts[i][j])==m.end())
                {
                    m[accounts[i][j]]=i;
                }
                else
                {
                    d.uni(m[accounts[i][j]],i);
                }
            }
        }
        vector<vector<string>> v;
        map<int,int> m2;
        int g = 0;

        for(auto it : m)
        {
            int f = d.finpar(it.second);
            if(m2.find(f)==m2.end())
            {
                m2[f]=g;
                g++;
                v.push_back({accounts[f][0]});
            }
            
            v[m2[f]].push_back(it.first);
        }
        return v;
    }
};