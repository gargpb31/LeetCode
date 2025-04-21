class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) 
    {
        int n = differences.size();

        vector<int> prefix(n);

        long long sum = 0;
        int minn = 0;
        int maxx = 0;
        for(int i =0; i<n; i++)
        {
            sum+=(differences[i]);
            prefix[i]=sum;
            minn=min(minn,sum);
            maxx=max(maxx,sum);

        }

        int y = upper-maxx;
        int y1 = lower+abs(minn);

        int y2 = y-y1+1;


        return max(y2,0);



    }
};