class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int j = 0;
        int n = g.size();
        int ns = s.size();
        int count = 0;
        for(int i=0; i<ns; i++)
        {
            if(j==n) break;
            if(s[i]>=g[j])
            {
                count++;
                j++;
            }
        }
        return count;
    }
};