class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int g1 = s.size()-1;
        int g2 = g.size()-1;

        int ans=0;
        while(g1>=0 && g2>=0){
            if(s[g1]>=g[g2]) {
                ans++;
                g2--;
                g1--;
            }
            else{
                g2--;
            }
        }
        return ans;

    }
};