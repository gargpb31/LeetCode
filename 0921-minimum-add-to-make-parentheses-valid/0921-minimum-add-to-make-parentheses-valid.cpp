class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        
        int c=0;
        int c1 = 0;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='(') c++;
            else
            {
                if(c>0) c--;
                else c1++;
            }
        }

       
         return c+c1;

    }
};