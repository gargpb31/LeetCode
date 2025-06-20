class Solution {
public:
    string shortestPalindrome(string s) {
        string f = s;
         reverse(s.begin(),s.end());

         string g = f;
         g+='+';
         g+=s;
        int n = g.size();
         vector<int> v(n);

        v[0]=0;
        for(int i=1; i<n; i++)
        {
            int j = v[i-1];
            while(j>0 && g[i]!=g[j]) j=v[j-1];

            if(g[i]==g[j]) j++;

            v[i]=j;
        }

        int n2 = f.size();

        int cm = 0;

        for(int i=n2+1; i<n; i++)
        {
            cm=max(cm,v[i]);
        }
        if(cm==n2) return f;

        string r = "";
        for(int i=cm; i<n2; i++) r+=f[i];
        reverse(r.begin(),r.end());
        return r+f;
         
    }
};