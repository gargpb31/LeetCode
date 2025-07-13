class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;

        int n = s.size();

        for(int i=0; i<n; i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                s1.push(s[i]);
            } 
            else
            {
                if(s1.empty()) return false;
                char d = s1.top();
                if(s[i]==')' && d=='(') 
                {
                    s1.pop();
                }
                else if(s[i]=='}' && d=='{') s1.pop();
                else if(s[i]==']' && d=='[') s1.pop();
                else return false;

            }
        }
        if(s1.empty())
        return true;

        return false;
    }
};