class Solution {
public:
    string removeOuterParentheses(string s) {
        int ou = 0;
        int c = 0;

        int n = s.size();
        string f = "";
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                if(ou==0) ou++;
                else {f+=s[i]; c++;}
            }
            else
            {
                if(c>0){f+=s[i]; c--;}
                else {ou--;}
            }
        }
        return f;
    }
};