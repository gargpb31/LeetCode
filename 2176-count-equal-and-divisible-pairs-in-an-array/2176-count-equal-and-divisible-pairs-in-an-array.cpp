class Solution {
public:
    int countPairs(vector<int>& nums, int k) 
    {
        //optimal solution in O(nums.size()*(sqrt(k)));

        //Precompute divisors of k 

        vector<int> divisors;

        for(int i=2; i*i<=k; i++)
        {
            if(k%i==0)
            {
                divisors.push_back(i);
                if((k/i)!=i)
                {
                    divisors.push_back((k/i));
                }
            }
        }

        divisors.push_back(k);
        if(k!=1) divisors.push_back(1);

        //Now we will precomput for every value in nums[i] that how many index are there

        unordered_map <int,vector<int> > m;

        //Insert : O(1) average : O(n) : worst case

        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]].push_back(i); 
        }

        int ans = 0;

        for(auto& [key,vec] : m)
        {
            unordered_map<int,int> mpp;

            for(int i : vec)
            {
                int gcdd = gcd(i,k);
                int need = k/gcdd;

                ans+=mpp[need];

                for(int j : divisors)
                {
                    if(i%j==0)
                    {
                        mpp[j]++;
                    }
                }
            }
        }
        return ans;


    }
};