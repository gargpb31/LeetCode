class DSU{
    public : vector<int> parent,rank;

    DSU(int size)
    {
        parent.resize(size);
        rank.resize(size,1);

        for(int i=0; i<size; i++)
        {
            parent[i]=i;
        }
    }

    int findpar(int node)
    {
        if(parent[node]==node) return node;

        return parent[node]=findpar(parent[node]);
    }

    void unite(int node1,int node2)
    {
        int parent1 = findpar(node1);
        int parent2 = findpar(node2);

        if(parent1==parent2)
        {
            return;
        }

        if(rank[parent1]<rank[parent2])
        {
            parent[parent1]=parent2;

        }
        else if (rank[parent1]>rank[parent2])
        {
            parent[parent2]=parent1;
        }
        else
        {
            parent[parent1]=parent2;
            rank[parent2]++;
        }
    }



};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int extraedges = 0;
        DSU d (n);
        for(auto it : connections)
        {
            int computer1 = it[0];
            int computer2 = it[1];

            int par_computer1 = d.findpar(computer1);
            int par_computer2 = d.findpar(computer2);

            if(par_computer1==par_computer2)
            {
                extraedges++;
            }
            else
            {
                d.unite(computer1,computer2);
            }
        }

        map<int,int> m;

        for(int i=0; i<n; i++)
        {
            int par_computer = d.findpar(i);
            m[par_computer]++;
        }
        int components = m.size();
        cout<<components;

        if(extraedges>=(components-1))
        {
            return components-1;
        }
        return -1;

    }
};