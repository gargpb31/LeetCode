class Solution {
public:
    bool vowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }

    int maxFreqSum(string s) {
        int n1 = 0;
        int n2 = 0;

        int n =s.size();
        map<char,int> m;
        for(int i=0; i<n; i++)
        {
            m[s[i]]++;
            if(vowel(s[i]))
            {
                n1=max(n1,m[s[i]]);
            }
            else
            {
                n2=max(n2,m[s[i]]);
            }
        }
        return n1+n2;
    }
};