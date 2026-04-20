class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(colors[i]!=colors[j])
                {
                    int dif = abs(i-j);
                    ans=max(ans,dif);
                }
            }
        }
        return ans;
    }
};