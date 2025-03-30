class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        map<char,int> m1,m2;

        int n = s.size();

        for(int i=0; i<n; i++)
        {
            m2[s[i]]=i;
            if(m1.find(s[i])==m1.end())
            {
                m1[s[i]]=i;
            }
        }

        int g=0;
        int g1=0;

        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            g1=max(g1,m2[s[i]]);

            if(g1==i)
            {
                ans.push_back(g1-g+1);
                g=g1+1;
            }
        }
        return ans;
    }
};