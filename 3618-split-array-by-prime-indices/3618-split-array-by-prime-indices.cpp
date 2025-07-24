class Solution {
public:

    vector<bool> isprime;

    void sieve()
    {
        isprime.resize(1e5,true);
        isprime[0]=false;
        isprime[1]=false;
    for(int i=2; i<1e5; i++)
    {
        if(isprime[i]==true)
        {
            for(int j=2*i; j<1e5; j+=i)
            {
                isprime[j]=false;
            }
        }
    }



    }

    long long splitArray(vector<int>& nums) {
        sieve();
        int n = nums.size();
        long long sum1=0,sum2=0;
        for(int i=0; i<n; i++)
        {
            if(isprime[i])
            {
                sum1+=nums[i];
            }
            else
            {
                sum2+=nums[i];
            }
        }
        return abs(sum1-sum2);
        
    }
};