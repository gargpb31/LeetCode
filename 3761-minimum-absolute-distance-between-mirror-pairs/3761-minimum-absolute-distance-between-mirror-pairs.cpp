class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        map<long long,int> m;
        m[nums[n-1]]=n-1;
           int d = n+1;
        for(int i =n-2; i>=0; i--)
        {
            int dig = nums[i];
            int rev = 0;
            while(dig!=0)
            {
                int x = dig%10;
                rev=rev*10+x;
                dig/=10;
            }
         
           
            
                long long xx = rev*pow(10,0);
                if(m.find(xx)!=m.end())
                {
                    d=min(d,m[xx]-i);
                }
            

            m[nums[i]]=i;

        }
        if(d==n+1) return -1;
        return d;
    }
};