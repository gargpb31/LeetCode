class Solution {
public:
    bool check(vector<int> &piles,int mid,int h)
    {
       long long count = 0;
        int size_piles = piles.size();
        for(int i = 0; i<size_piles; i++)
        {
            int scount = piles[i]/mid;
            if(piles[i]%mid!=0) scount++;

            count+=(scount);
        }

        long long h1 =h;

        if(count<=h1) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h)
    
    {
        int low = 1;
        int high = 1e9;

        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(check(piles,mid,h))
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};