class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int g1=g.size();
        int s1=s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int ans = 0;
        int ss = 0;
        int gg = 0;
        while(1)
        {
            if(ss==s1 || gg==g1) break;
            if(s[ss]>=g[gg])
            {
                ans++;
                ss++;
                gg++;
            }
            else 
            {
                ss++;
            }
        }
        return ans;
    }
};