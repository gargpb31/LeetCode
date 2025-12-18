class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int j=-1;
        string ss="";
        int c=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]==' ')
            {
                
                j=i+1;
                break;
            }
            ss+=s[i];
            if(s[i]=='a') c++;
            else if(s[i]=='e') c++;
            else if(s[i]=='i') c++;
            else if(s[i]=='o') c++;
            else if(s[i]=='u') c++;
        }
        if(j==-1) return s;
        int cr=0;
        
        vector<string> v;
        v.push_back(ss);
        ss="";
        for(int i=j; i<n; i++)
        {
           

            if(s[i]==' ')
            {
                if(cr==c)
                {
                    reverse(ss.begin(),ss.end());
                    v.push_back(ss);
                }
                else
                {
                    v.push_back(ss);
                }
                cr=0;
                ss="";
                continue;
            }
             ss+=s[i];
            if(s[i]=='a') cr++;
            else if(s[i]=='e') cr++;
            else if(s[i]=='i') cr++;
            else if(s[i]=='o') cr++;
            else if(s[i]=='u') cr++;

        }
        if(cr==c)
        {
             reverse(ss.begin(),ss.end());
                   
        }
         v.push_back(ss);
         string ans ="";
        int n2=v.size();
        for(int i=0; i<n2; i++)
        {
            ans+=v[i];
            if(i!=n2-1)
            ans+=' ';
        }
        return ans;
    }
};