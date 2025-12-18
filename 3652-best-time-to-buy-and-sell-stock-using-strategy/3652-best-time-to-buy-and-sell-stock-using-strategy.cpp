class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> add(n);
        long long x = 0;
        vector<long long> add2(n);
        long long y= 0;
        for(int i=0; i<n; i++)
        {
            x+=prices[i];
            add[i]=x;
            y+=(prices[i]*strategy[i]);
            add2[i]=y;
        }
        long long ans=y;
        for(int i=0; i<=(n-k); i++)
        {
            long long r = add2[i+k-1];
            if(i!=0) r-=add2[i-1];
            long long r2 = add[i+k-1]-add[i+(k/2-1)];
            long long z = y-r+r2;
            ans=max(ans,z);
        }
        return ans;    
    }
};