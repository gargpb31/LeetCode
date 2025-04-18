class Solution {
public:

int maxk = 1000001;

long long binomial(int n,int k)
{
    if(k>n) return 0;
    if(k>(n-k)) k=n-k;

    long long res = 1;
    for(int i=1; i<=k; i++)
    {
        res = res * (n-i+1)/i;
        if(res>=maxk) return maxk;
     }

    return res;
}

long long multinomial(vector<int> &half)
{
    int total = accumulate(half.begin(),half.end(),0);
    long long res = 1;
    for (int i = 0; i < 26; i++)
    {
        int cnt = half[i];
        res *= binomial(total, cnt);
        if(res>=maxk) return maxk;
        total -= cnt;
    }

    return res;

}



    string smallestPalindrome(string s, int k)
    {
        map<char,int> m;

        for(int i=0; i<s.size(); i++)
        {
            m[s[i]]++;
        }

        string middle = "";

        for(auto it : m)
        {
            if(it.second%2!=0) middle+=it.first;
        }

        vector<int> v(26);

        for(auto it : m)
        {
            int x = it.first-'a';
            v[x]+=(it.second/2);
        }

        int total = accumulate(v.begin(),v.end(),0);
        long long tt = multinomial(v);
        if(k>tt) return "";
        string left = "";
        for(int j=0; j<total; j++)
       {
            for(int i=0; i<26; i++)
            {
                if(v[i]!=0)
                {
                    v[i]--;
                    char c = 'a'+i;
                    long long c1 = multinomial(v);
                    if(c1>=k)
                    {
                        left+=c;
                        break;
                    }
                    else
                    {
                        k-=c1;
                        v[i]++;
                    }
                }
            }
        
       }

       string right = left;
       reverse(right.begin(),right.end());

       return (left+middle+right);




    }
};