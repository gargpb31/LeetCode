class Solution {
public:
    string countAndSay(int n) 
    {
        if(n==1) return "1";
        if(n==2) return "11";
        if(n==3) return "21";
      
        string k = "21";
        for(int i=4; i<=n; i++)
        {   
            string k1 = "";
            int count = 1;
            for(int j=0; j<k.size()-1; j++)
            {
                if(k[j]==k[j+1]) count++;
                else
                {
                    char c = count+'0';
                    k1+=c;
                    k1+=k[j];
                    count = 1;
                }
            }
             char c1 = count+'0';
             k1+=c1;
             k1+=k[k.size()-1];
             k=k1;

        }
        return k;

    }
};