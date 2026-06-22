class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();

        map<char,int> m;
        for(int i=0; i<n; i++)
        {
            m[text[i]]++;
        }

        int ans = n;
        ans=min(ans,m['b']);
        ans=min(ans,m['a']);
        ans=min(ans,m['n']);
        m['l']/=2;
        m['o']/=2;
        ans=min(ans,m['l']);
        ans=min(ans,m['o']);
        return ans;
    }
};