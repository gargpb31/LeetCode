class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

           vector<int> ans;

        int x1 = n-k+1;
        for(int j=0; j<x1; j++)
        {   
            map<int,int> m;
            int sum = 0;
            for(int i=j; i<k+j; i++)
            {   
                m[nums[i]]++;
                sum+=nums[i];
            }
            if(m.size()<=x)
            {
                ans.push_back(sum);
                continue;
            }
            vector<pair<int,int>> v;
            for(auto it : m)
            {
                v.push_back({it.second,it.first});
            }
            sort(v.rbegin(),v.rend());

            sum=0;
            for(int kk=0; kk<x; kk++)
            {
                sum+=(v[kk].first*v[kk].second);
            }
            ans.push_back(sum);

        }
        return ans;


    }
};