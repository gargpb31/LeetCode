class Solution {
public:
    int residuePrefixes(string s) {
        map<char,int> m;
        int n= s.size();
        int count=0;
        for(int i=0; i<n; i++)
        {
            m[s[i]]++;
            if(((i+1)%3==m.size())) count++;
        }
        return count;
    }
};