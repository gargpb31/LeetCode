class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m;
       map<char,int> m2;

        int n = s.size();

        for(int i=0; i<n; i++)
        {
            
                if(m.find(s[i])==m.end()) {
                    m[s[i]]=t[i];
                   if(m2.find(t[i])==m2.end()) m2[t[i]]=1;
                   else return false;

                }
                else
                {
                    if(m[s[i]]!=t[i]) return false;

                }
            
           
        }
        return true;
    }
};