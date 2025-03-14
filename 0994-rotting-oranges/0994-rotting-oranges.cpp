class Solution {
public:

   
    int orangesRotting(vector<vector<int>>& v) {
       queue<pair<pair<int,int> ,int> > q;
        int n =v.size();
        int m = v[0].size();
                for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]==2) {
                   q.push({{i,j},0});
                }
            }
        }
        int cnt =0;
               
               int ans =0;
            
                while(!q.empty()){
                   
                        
                   
                    int x = q.front().first.first;
                    int y = q.front().first.second;
                    int z = q.front().second;
                    q.pop();
                    z++;
                    if((x+1)<n && v[x+1][y]==1){
                        v[x+1][y]=2;
                        ans=max(ans,z);
                        q.push({{x+1,y},z});
                    }
                    if((x-1) >=0 && v[x-1][y]==1){
                        v[x-1][y]=2;
                            q.push({{x-1,y},z});
                            ans=max(ans,z);
                    }
                    if(y+1<m && v[x][y+1]==1){
                        v[x][y+1]=2;
                            q.push({{x,y+1},z});
                            ans=max(ans,z);
                    }
                    if(y-1>=0 && v[x][y-1]==1){
                        v[x][y-1]=2;
                            q.push({{x,y-1},z});
                            ans=max(ans,z);
                    }
               
                    

                }
        
            int flag=0;
            
 for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]==1) {
                    flag=1;
                }
            }
 }

 if(flag==1) return -1;
 return ans;

    }
};