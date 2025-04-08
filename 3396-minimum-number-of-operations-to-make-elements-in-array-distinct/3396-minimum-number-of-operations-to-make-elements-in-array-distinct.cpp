class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        map<int,int> m;

        for(int i=0; i<n; i++)
        {
            m[nums[i]]++;
        }
        if(m.size()==n) return 0;
        for(int i=0; i<n; i++)
        {
            m[nums[i]]--;
            int flag=0;
            for(auto it : m)
            {
                if(it.second>1)
                {
                    flag++;
                }
            }
            if(flag==0)
            {
                int ans = (i+1)/3;
                if((i+1)%3!=0)
                {
                    ans++;
                }
                return ans;
            }
        }
        return -1;

    }
};