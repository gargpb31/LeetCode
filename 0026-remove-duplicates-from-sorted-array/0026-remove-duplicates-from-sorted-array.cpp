class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size();

        for(int i=0; i<n; i++) m[nums[i]]++;


        vector<int> ans(n,0);
        int g = 0;
        for(auto it : m)
        {
            ans[g]=it.first;
            g++;
        }
        
        nums=ans;
        return m.size();
    }
};