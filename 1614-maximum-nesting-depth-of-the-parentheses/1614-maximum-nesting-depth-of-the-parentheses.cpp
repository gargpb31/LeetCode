class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        int m = 0;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(') m++;
            else if(s[i]==')')
            {
                m--;
            }
            ans=max(ans,m);
        }
         ans=max(ans,m);
         return ans;
    }
};