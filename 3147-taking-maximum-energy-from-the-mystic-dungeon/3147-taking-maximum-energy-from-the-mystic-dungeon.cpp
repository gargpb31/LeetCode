class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = -100000000;

        map<int,int> m;
        for(int i=n-1; i>=0; i--)
        {
            m[i%k]+=(energy[i]);
            ans=max(m[i%k],ans);
        }

        return ans;
    }
};