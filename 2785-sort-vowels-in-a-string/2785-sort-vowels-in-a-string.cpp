class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        //logic : extract all vowels in a vector sort them and then place at desired places

        vector<char> v;

        map<char,int> m;
        m['A']=m['E']=m['I']=1;
        m['O']=m['U']=1;

        m['a']=m['e']=m['i']=1;
        m['o']=m['u']=1;

        for(int i=0; i<n; i++)
        {
            if(m[s[i]]==1)
            {
                v.push_back(s[i]);
            }
        }

        if(v.size()==0) return s;
        int g =0;

        sort(v.begin(),v.end());

        for(int i=0; i<n; i++)
        {
            if(m[s[i]]==1)
            {
                s[i]=v[g];
                g++;
            }
        }
        return s;




    }
};