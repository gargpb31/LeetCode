class Solution {
public:

 int modExp(int base, int exp, int mod)
{
int result = 1;
while (exp > 0)
 {
 if (exp % 2 == 1)
{
result = (1ll*result * base) % mod;
 }
 base = (1ll*base * base) % mod;
 exp /= 2;
 }
 return result;
}


    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        n++;
        vector<vector<int>> graph(n+1);

        for(auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<int> visited(n+1,0);
        queue<pair<int,int>> q;
        visited[1]=1;
        q.push({1,0});

        vector<int> v(n+1,0);
        vector<int> v1(n+1,0);
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto it : graph[x])
            {
                if(visited[it]==0)
                {
                    visited[it]=1;
                    v[it]=x;
                    v1[it]=y+1;
                    q.push({it,y+1});
                }
            }

            
        }

        int f = *max_element(v1.begin(),v1.end());
        cout<<f<<endl;
        
        int ans = modExp(2,f-1,1e9+7);
        return ans;








    }
};