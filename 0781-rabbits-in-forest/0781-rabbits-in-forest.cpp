class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();

        map<int,int> m;

        int count = 0;
        

        for(int i = 0; i<n; i++)
        {
            m[answers[i]]++;
            count+=(answers[i]);
        }
  
        for(auto it : m)
        {
            
            int x = (it.second/(it.first+1));
          
            int r = (it.second%(it.first+1));
            
            count -= (x*(it.first*it.first));
             count -= (x*(it.first));
            if(r==0) continue;
            count-=((r-1)*it.first);
        
            count-=(r-1);
        }
        count+=n;
        return count;
    }
};