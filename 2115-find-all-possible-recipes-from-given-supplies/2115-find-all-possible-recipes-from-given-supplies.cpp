class Solution {
public:
 map<int,string> m3;
    void dfs(map<string,int> &m2, vector<vector<string>>& ingredients,map<string,int> &m1,int n,vector<string> &ans,vector<int> &visited){
            if(visited[n]==0){
                visited[n]=1;
                int count=0;
                for(auto it : ingredients[n]){
                    if(m1.find(it)==m1.end()){
                        if(m2.find(it)!=m2.end()){
                            dfs(m2,ingredients,m1,m2[it],ans,visited);

                        }

                    }

                    if(m1.find(it)!=m1.end()) count++;
                }
                if(count==ingredients[n].size()){
                    ans.push_back(m3[n]);
                    m1[m3[n]]++;
                }
            }
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,int> m;
        for(auto it : supplies){
            m[it]++;
        }
        
        vector<string> ans;
        map<string,int> m2;
       

        int g=0;
        for(auto it : recipes){
            m2[it]=g;
            m3[g]=it;
            g++;
        }
        vector<int> visited(g,0);
        for(int i=0; i<g; i++){
            if(m.find(recipes[i])==m.end()){
        dfs(m2,ingredients,m,i,ans,visited);

            }
    }
        
        
        return ans;
    }
};