class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        set<int> s;
        s.insert(nums[0]);
        int ans=0;
        int t=0;
        int g1=1;
        while(t<nums.size()-1){
            auto it = s.end();
            it--;
            int g = (*it);
            s.erase(it);
            
            t=max(t,g);
            t = min(t, (int)nums.size() - 1);
            ans++;
            while(g1<=t){
                int x = nums[g1]+g1;
                x = min(x, (int)nums.size() - 1);
                s.insert(x);
                g1++;
            }
        }
        return ans;
    }
};