class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m;
        int n = s.size();
        int m1 = t.size();

        if(m1!=n) return false;

        for(int i=0; i<n; i++) m[t[i]]++;

        for(int i=0; i<n; i++)
        {
            if(m.find(s[i])==m.end()) return false;
            if(m[s[i]]==0) return false;

            m[s[i]]--;
        }
        return true;

    }
};