class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();

       vector<int> v1,v2;
       v1.push_back(-1);
       
       s.push(nums[0]);
        for(int i=1; i<n; i++)
        {
           while(!s.empty() && s.top() < nums[i])
            {
                s.pop();

            }
            if(s.empty()) {
                v1.push_back(-1);
                s.push(nums[i]);
            }
            else
            {
                if(s.top()==nums[i-1]) v1.push_back(-1);
                else v1.push_back(s.top());

                s.push(nums[i]);
            }



        }
        long long ans = 0;
        for(int i=0; i<n; i++)

        {
            if(v1[i]!=-1) ans++;
        }
        v1.clear();
        while(!s.empty()) s.pop();
        s.push(nums[n-1]);
        for(int i=n-2; i>=0; i--)
        {
            while(!s.empty() && s.top() < nums[i])
            {
                s.pop();

            }
             if(s.empty()) {
               
                s.push(nums[i]);
            }
             else
            {
                if(s.top()==nums[i+1]) v1.push_back(-1);
                else {v1.push_back(s.top()); ans++;}

                s.push(nums[i]);
            }
        }
        return ans;


        



    }
};