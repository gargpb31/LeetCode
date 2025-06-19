class Solution {
public:
    int strStr(string haystack, string needle) {
        string finali = needle;
        finali+='+';
        finali+=haystack;

        int n = finali.size();
        int m = needle.size();
        cout<<finali<<endl;
        vector<int> v(n);
        v[0]=0;
        for(int i=1; i<n; i++)
        {
            int j = v[i-1];
            while(j>0 && finali[i]!=finali[j])
            {
                j=v[j-1];
            }
            if(finali[i]==finali[j]) j++;
            v[i]=j;
        }
        for(int i=0; i<n; i++)
        {
            cout<<v[i]<<" ";
        }

        for(int i=m+1; i<n; i++)
        {
            if(v[i]==m)
            {
                return i-m-(m);
            }
        }
        return -1;
    }
};