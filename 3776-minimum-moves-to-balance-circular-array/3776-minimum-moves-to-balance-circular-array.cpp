class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        int c = -1;
        for(int i=0; i<n; i++) 
        {
            if(balance[i]<0) c=i;
        }
        if(c==-1) return 0;
        vector<int> v(n,0);
        for(int i=0; i<n; i++)
        {
            int x=0,y=0;
            if(c>i)
            {
                x=c-i;
                y=n-c+i;
            }
            else
            {
                x=i-c;
                y=n-i+c;
            }
            v[i]=min(x,y);
        }
        for(int i=0; i<n; i++) cout<<v[i]<<" ";
        cout<<endl;

        map<int,int> m;
        for(int i=0; i<n; i++)
        {
            if(v[i]!=0)
            {
            m[v[i]]+=balance[i];
            }
        }
        int r = balance[c];
        balance[c]=abs(r);
        long long ans=0;
        for(auto it : m)
        {
            if(balance[c]>=it.second)
            {
                balance[c]-=it.second;
                ans+=1ll*it.second*it.first;
            }
            else
            {
                ans+=(1ll*balance[c])*it.first;
                balance[c]=0;
            }

        }
        if(balance[c]>0) return -1;
        return ans;
    }
};