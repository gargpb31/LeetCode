class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> v;
        int ans = 0;
        for(int i=n-1; i>=0; i--)
        {
            ans=max(ans,prices[i]);
            v.push_back(ans);
        }
        reverse(v.begin(),v.end());
        ans=0;
        for(int i=0; i<n-1; i++)
        {
            int p = v[i+1]-prices[i];
            ans=max(ans,p);
        }
        return ans;
    }
};