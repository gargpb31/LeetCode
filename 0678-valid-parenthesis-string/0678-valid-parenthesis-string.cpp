class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        int n = s.size();

        for(int i=0; i<n; i++)
        {
           
            if(s[i]=='(') 
            {
                low++; high++;
            }
            else if (s[i]=='*')
            {
                low--;
                low=max(low,0);
                high++;
            }
            else
            {
                low--;
                low=max(low,0);
                high--;
            }
             if(high<0) return false;
        }
        if(low==0) return true;
        return false;
    }
};