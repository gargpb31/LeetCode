class Solution {
public:

    bool func(vector<int> &weights,int mid,int days)
    {
        int d = 0;

        int sum = 0;

        for(int i=0; i<weights.size(); i++)
        {
            if(weights[i]>mid) return false;
            sum+=weights[i];
            if(sum>mid)
            {
                d++;
                sum=weights[i];

            }
        }
        d++;
        if(d>days) return false;
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1;
        int high = 25000000;


        while(low<=high)
        {
            int mid = (low+(high-low)/2);

            if(func(weights,mid,days))
            {
                high = mid -1;
            }
            else
            {
                low=mid+1;
            }

        }
        return low;
    }
};