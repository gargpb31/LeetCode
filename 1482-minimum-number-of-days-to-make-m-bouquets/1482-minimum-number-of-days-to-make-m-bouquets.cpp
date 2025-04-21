class Solution {
public:

    bool check(vector<int>& bloomDay, int mid, int k, int m)
    {
        int n = bloomDay.size();

        vector<int> v(n,0);

        for(int i=0; i<n; i++)
        {
            if(bloomDay[i]<=mid) v[i]=1;
        }

        int count = 1;
        int y = 0;
        for(int i=0; i<n-1; i++)
        {
            if(v[i]==v[i+1] && v[i]==1) count++;
            else
            {
                if(v[i]==1)
                {
                        y+=(count/k);
                }
                count=1;
            }
        }
        if(v[n-1]==1)
        {
             y+=(count/k);
        }

        if(y>=m) return true;
        return false;

    }

    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int low =1;
        int high = 1e9;

        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(check(bloomDay,mid,k,m))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(low>1e9) return -1;
        return low;
    }
};