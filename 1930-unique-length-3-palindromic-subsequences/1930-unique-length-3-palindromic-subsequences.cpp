class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        map<char,int> m;
        map<char,int> m1,m2;

        for(int i=0; i<n; i++)
        {
            m[s[i]]++;
            if(m1.find(s[i])==m1.end()) m1[s[i]]=i;
            m2[s[i]]=i;
        }
        int ans=0;

        for(auto it : m)
        {
            if(it.second>=2)
            {
                int x1=m1[it.first];
                int x2=m2[it.first];
                map<int,int> c;
                for(int i=x1+1; i<x2; i++)
                {
                    c[s[i]]++;
                }
                ans+=(c.size());
            }
        }
        return ans;


    }
};