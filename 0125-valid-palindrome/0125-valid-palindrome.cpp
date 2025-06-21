class Solution {
public:
    bool isPalindrome(string s) {
        map<char,char> m;
        for(int i=0; i<26; i++)
        {
            char c = 'A'+i;
            char d = 'a'+i;
            m[c]=d;
            m[d]=d;

        }
        for(int i=0; i<10; i++)
        {
            char c = '0'+i;
            m[c]=c;
        }

        int n = s.size();
        string h = "";
        for(int i=0; i<n; i++)
        {
            if(s[i]!=' ')
            {
                if(m.find(s[i])!=m.end()) 
                {
                    h+=m[s[i]];
                }
            }
        }
        if(h==" ")return true;
        string f = h;
        reverse(h.begin(),h.end());
        if(h==f) return true;
        return false;


    }
};