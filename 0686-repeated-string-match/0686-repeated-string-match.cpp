class Solution {
public:

    int repeatedStringMatch(string a, string b) {
        const long m = 1e9+9;
        int n1 = a.size();
        int n2 = b.size();

        const int p =31;

        string f = a;

       while((a.size()-f.size()+1)<b.size())
       {
        a+=f;
       }




          vector<long long> p_pow(a.size()); 
            p_pow[0] = 1; 
        for (int i = 1; i < (int)p_pow.size(); i++) 
         p_pow[i] = (p_pow[i-1] * p) % m;


    n1=a.size();
        vector<long long> h(n1+1,0);

        for(int i=0; i<a.size(); i++)
        {
            h[i+1]=(h[i]+(a[i]-'a'+1)*p_pow[i])%m;

        }

        long long h_b = 0;
    n2=b.size();
        for(int i=0; i<b.size(); i++)
        {
            h_b=(h_b+(b[i]-'a'+1)*p_pow[i])%m;
        }
        int t=-1;
        for(int i=0; i+n2-1<n1; i++)
        {
            long long c = (h[i+n2]+m-h[i])%m;

            if(c==h_b*p_pow[i]%m)
            {
                t=i;
                break;
            }
        }

        if(t==-1) return -1;
        int r = t+n2;
        if(r<=f.size()) return 1;
        int y = f.size();
        if(r%y==0) return r/y;
        else return (r/y+1);
        



    }
};