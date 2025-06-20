class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;

        string f = "";
        int n = s.size();

        for(int i=0; i<n; i++)
        {
            if(s[i]!=' ')
            {
                f+=s[i];
            }
            else
            {
                if(f!="")
                v.push_back(f);
                f="";
            }
        }
        if(s[n-1]!=' ')
         v.push_back(f);
      
        reverse(v.begin(),v.end());
        int b = v.size();
        string ans;
        for(int i=0; i<b; i++)
        {
            ans+=v[i];
            ans+=" ";
        }
        ans.pop_back();

        return ans;
    }
};