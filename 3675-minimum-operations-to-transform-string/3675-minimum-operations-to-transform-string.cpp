class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        map<char,int> m;
        int z = 1;
        for(int i=25; i>=0; i--)
        {
           char c = 'a'+i;
           m[c]=z;
           z++;
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i]!='a')
            ans=max(ans,m[s[i]]);
        }
        return ans;


    }
};