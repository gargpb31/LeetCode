class Solution {
public:
    int characterReplacement(string s, int k) {
        multiset<int> m;
        map<char,int> m1;
        int n = s.size();
        int a=0;
        int b=0;
        int ans = 0;
        while(b<n)
        {
            if(m1.find(s[b])==m1.end() || m1[s[b]]==0)
            {
                m.insert(1);
                m1[s[b]]++;
            }
            else
            {
                m.erase(m.find(m1[s[b]]));
                m1[s[b]]++;
                m.insert(m1[s[b]]);

            }

            int len = b-a+1;
            int r = len-*m.rbegin();
            
            if(r<=k)
            {
                ans=max(ans,b-a+1);
                b++;
            }
            else
            {
                while(r>k)
                {
                    m.erase(m.find(m1[s[a]]));
                m1[s[a]]--;
                if(m1[s[a]]!=0)
                m.insert(m1[s[a]]);
                a++;
                len=b-a+1;
                r=len-*m.rbegin();

                }
                b++;
            }
        }
        b--;
        ans=max(b-a+1,ans);
        return ans;
    }
};