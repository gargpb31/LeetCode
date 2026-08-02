class Solution {
public:
    int minDays(vector<int>& bloomday, int m, int k) {
        int n = bloomday.size();
        int high = 1e9;
        int low = 1;

        while(low<=high)
        {
            int mid = (low+high)/2;
            int c = 0;
            int c2=0;
            for(int i=0; i<n; i++)
            {
                if(bloomday[i]<=mid)
                {
                    c2++;
                    if(c2==k) {c++; c2=0;}
                }
                else
                {
                    c2=0;
                }
            }
            if(c>=m) high=mid-1;
            else low=mid+1;

        }
        if(low>1e9) return -1;
        return low;
    }
};