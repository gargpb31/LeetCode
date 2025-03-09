class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count = 0 ;
        int init = 1;
        int fin = k;
        fin%=(colors.size());
        int flag=0;
        vector<int> v(colors.size(),0);
        for(int i=0; i<colors.size()-1; i++){
            if(colors[i]==colors[i+1]) v[i]=1;
        }
        if(colors[colors.size()-1]==colors[0]) v[colors.size()-1]=1;
        vector<int> c(colors.size());
        c=v;
        for(int i=1; i<colors.size(); i++){
            v[i]+=v[i-1];
        }
       

        for(int i=0; i<k-1; i++){
            if(colors[i]==colors[i+1]){
                flag=1;
            }
        }
        if(flag==0) count++;
        
        
        while(init<colors.size()){
           int x = v[fin];
          if(init<fin){
            x-=v[init-1];
          }
          else{
            int y = v[colors.size()-1];
            y-=v[init-1];
            x+=y;
          }
          x-=c[fin];
          
           if(x==0){
                count++;
           }
           init++;
           fin+=1;
           fin%=(colors.size());
        }
        return count;
    }
};