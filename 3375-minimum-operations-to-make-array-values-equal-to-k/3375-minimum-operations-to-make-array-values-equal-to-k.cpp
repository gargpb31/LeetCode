class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int size_nums = nums.size();

        for(int i=0; i<size_nums; i++)
        {
            if(nums[i]<k) return -1;
        }

        map<int,int> m;
        for(auto it : nums)
        {
            m[it]++;
        }

        if(m.find(k)==m.end()) return m.size();
        return m.size()-1;
    }
};