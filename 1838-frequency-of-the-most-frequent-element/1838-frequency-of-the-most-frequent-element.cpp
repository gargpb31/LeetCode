class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

       
        map<int,int> m;
        for(int i=0; i<n; i++) m[nums[i]]++;
        vector<int> v;
        for(auto it : m)
        {
            v.push_back(it.first);
        }
        int s = v.size();
        int ans = 0;
        for(int i=0; i<s; i++)
        {
            int j = k;
            int c = 0;
            int g = i-1; 
            while(j!=0 && g>=0)
            {
                int d = v[i]-v[g];
                if(d<=j)
                {
                    int r = j/d;
                    r=min(r,m[v[g]]);
                    j-=(d*r);
                    c+=(r);
                }
                else break;
                g--;
            }
            ans=max(ans,c+m[v[i]]);

        }
        return ans;
    }
};