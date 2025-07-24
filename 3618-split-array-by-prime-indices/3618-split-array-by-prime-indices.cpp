class Solution {
public:

    bool isprime(int n)
    {
        if(n<=1) return false;
        if(n==2) return true;
        int div = 0;
        for(int i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                div++;

            }
        }
        if(div==0) return true;
        return false;

    }

    long long splitArray(vector<int>& nums) {
       
        int n = nums.size();
        long long sum1=0,sum2=0;
        for(int i=0; i<n; i++)
        {
            if(isprime(i))
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